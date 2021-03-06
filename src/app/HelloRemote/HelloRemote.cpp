/*
  EbbRT: Distributed, Elastic, Runtime
  Copyright (C) 2013 SESA Group, Boston University

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as
  published by the Free Software Foundation, either version 3 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Affero General Public License for more details.

  You should have received a copy of the GNU Affero General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "app/app.hpp"
#include "ebb/Console/RemoteConsole.hpp"
#include "ebb/EbbManager/PrimitiveEbbManager.hpp"
#include "ebb/EventManager/SimpleEventManager.hpp"
#include "ebb/Gthread/Gthread.hpp"
#include "ebb/MemoryAllocator/SimpleMemoryAllocator.hpp"
#include "ebb/Syscall/Syscall.hpp"

#ifndef __bg__
#include "ebb/MessageManager/EthernetMessageManager.hpp"
#else
#include "ebb/MessageManager/MPIMessageManager.hpp"
#endif

#ifdef __linux__
#include "ebbrt.hpp"
#ifndef __bg__
#include "ebb/Ethernet/RawSocket.hpp"
#else
#include <iostream>
#include <mpi.h>
#endif
#elif __ebbrt__
#include "ebb/PCI/PCI.hpp"
#include "ebb/Ethernet/VirtioNet.hpp"
#endif

constexpr ebbrt::app::Config::InitEbb late_init_ebbs[] =
{
#ifdef __linux__
  { .name = "EbbManager" },
#endif
  { .name = "EventManager" },
  { .name = "Console" },
  { .name = "MessageManager" }
};

#ifdef __ebbrt__
constexpr ebbrt::app::Config::InitEbb early_init_ebbs[] =
{
  { .name = "MemoryAllocator" },
  { .name = "EbbManager" },
  { .name = "Gthread" },
  { .name = "Syscall" }
};
#endif

constexpr ebbrt::app::Config::StaticEbbId static_ebbs[] = {
  {.name = "MemoryAllocator", .id = 1},
  {.name = "EbbManager", .id = 2},
  {.name = "Gthread", .id = 3},
  {.name = "Syscall", .id = 4},
  {.name = "EventManager", .id = 5},
  {.name = "Console", .id = 6},
  {.name = "MessageManager", .id = 7}
};

const ebbrt::app::Config ebbrt::app::config = {
  .space_id = 1,
#ifdef __ebbrt__
  .num_early_init = sizeof(early_init_ebbs) / sizeof(Config::InitEbb),
  .early_init_ebbs = early_init_ebbs,
#endif
  .num_late_init = sizeof(late_init_ebbs) / sizeof(Config::InitEbb),
  .late_init_ebbs = late_init_ebbs,
  .num_statics = sizeof(static_ebbs) / sizeof(Config::StaticEbbId),
  .static_ebb_ids = static_ebbs
};

#ifdef __ebbrt__
void
ebbrt::app::start()
{
  pci = EbbRef<PCI>(ebb_manager->AllocateId());
  ebb_manager->Bind(PCI::ConstructRoot, pci);
  ethernet = EbbRef<Ethernet>(ebb_manager->AllocateId());
  ebb_manager->Bind(VirtioNet::ConstructRoot, ethernet);
  console->Write("Hello World (remote)\n");
}
#endif

#ifdef __linux__
int main(int argc, char** argv)
{
#ifdef __bg__
  if (MPI_Init(&argc, &argv) != MPI_SUCCESS) {
    std::cerr << "MPI_Init failed" << std::endl;
    return -1;
  }
#endif
  ebbrt::EbbRT instance;

  ebbrt::Context context{instance};
  context.Activate();
#ifndef __bg__
  ebbrt::ethernet = ebbrt::EbbRef<ebbrt::Ethernet>(ebbrt::ebb_manager->AllocateId());
  ebbrt::ebb_manager->Bind(ebbrt::RawSocket::ConstructRoot, ebbrt::ethernet);
  ebbrt::message_manager->StartListening();
  ebbrt::console->Write("Hello World (frontend)\n");
#else
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  if (rank == 0) {
    ebbrt::message_manager->StartListening();
  }
  if (MPI_Barrier(MPI_COMM_WORLD) != MPI_SUCCESS) {
    std::cerr << "MPI_Barrier failed" << std::endl;
    return -1;
  }
  if (rank == 0) {
    ebbrt::console->Write("Hello World (frontend)\n");
  } else {
    ebbrt::console->Write("Hello World (remote)\n");
  }
#endif
  context.Loop(-1);

  return 0;
}
#endif

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
#ifndef EBBRT_EBB_REMOTECONSOLE_REMOTECONSOLE_HPP
#define EBBRT_EBB_REMOTECONSOLE_REMOTECONSOLE_HPP

#include <functional>

#include "ebb/ebb.hpp"
#include "ebb/Console/Console.hpp"

namespace ebbrt {
  class RemoteConsole : public Console {
  public:
    static EbbRoot* ConstructRoot();
    virtual void Write(const char* str,
                       std::function<void()> cb = nullptr) override;
    virtual void HandleMessage(const uint8_t* message,
                               size_t len) override;
  };
}
#endif

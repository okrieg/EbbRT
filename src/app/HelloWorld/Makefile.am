# EbbRT: Distributed, Elastic, Runtime
# Copyright (C) 2013 SESA Group, Boston University

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.

# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
EXTRA_PROGRAMS += src/app/HelloWorld/HelloWorld

src_app_HelloWorld_HelloWorld_SOURCES = \
	src/app/HelloWorld/HelloWorld.cpp

src_app_HelloWorld_HelloWorld_ebbs = \
	src/ebb/EbbManager/libPrimitiveEbbManager.a \
	src/ebb/EventManager/libSimpleEventManager.a

if LRT_BARE
src_app_HelloWorld_HelloWorld_ebbs += \
	src/ebb/MemoryAllocator/libSimpleMemoryAllocator.a \
	src/ebb/Syscall/libSyscall.a \
	src/ebb/Gthread/libGthread.a
endif

src_app_HelloWorld_HelloWorld_LDFLAGS = \
	$(app_linkflags) \
	-Wl,-whole-archive \
	$(ebbrt_libs) \
	$(src_app_HelloWorld_HelloWorld_ebbs) \
	-Wl,-no-whole-archive

src_app_HelloWorld_HelloWorld_LDADD = \
	libebbrt.a

src_app_HelloWorld_HelloWorld_DEPENDENCIES = \
	libebbrt.a \
	$(app_deps) \
	$(ebbrt_libs) \
	$(src_app_HelloWorld_HelloWorld_ebbs)

if LRT_ULNX
src_app_HelloWorld_HelloWorld_LDFLAGS += \
	-pthread
endif

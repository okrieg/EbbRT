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
#ifndef EBBRT_LRT_EVENT_HPP
#error "Don't include this file directly"
#endif

#ifdef __bg__
#include <functional>
#endif

#include <sys/epoll.h>

#include "lrt/Location.hpp"

namespace ebbrt {
  namespace lrt {
    namespace event {
      /**
       * @brief Get cores location
       *
       * @return
       */
      Location get_location();

      unsigned get_max_contexts();

#ifdef __bg__
      /** Register a function to cause an event to be invoked.
          This is a workaround for lack of facilities to interrupt the
          event loop on CNK. The return value of the function is the
          interrupt to be invoked or -1 if none. */
      void register_function(std::function<int()> func);
#endif
    }
  }
}

#ifndef KRIVOSHAPOV_ITRAIT_HPP
#define KRIVOSHAPOV_ITRAIT_HPP

#include <cstddef>

namespace krivoshapov {
  struct ITrait {
    virtual ~ITrait() = default;
    virtual size_t operator()() const = 0;
    virtual void operator()(int a) = 0;
  };
}

#endif

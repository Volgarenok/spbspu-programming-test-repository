#ifndef KRIVOSHAPOV_DIV_REM_HPP
#define KRIVOSHAPOV_DIV_REM_HPP

#include <limits>

#include "itrait.hpp"

namespace krivoshapov {
  struct DivRem: ITrait {
    DivRem():
      count_(0),
      prev_(std::numeric_limits< int >::max()),
      n_(0)
    {}

  private:
    size_t count_;
    int prev_;
    size_t n_;

    void upd(int a) override;
    size_t result() const override;
    const char* name() const override;
  };
}

#endif

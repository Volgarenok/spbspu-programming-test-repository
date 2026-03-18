#ifndef KRIVOSHAPOV_DIV_REM_HPP
#define KRIVOSHAPOV_DIV_REM_HPP

#include "itrait.hpp"

namespace krivoshapov {
  struct DivRem: ITrait {
    DivRem();
    size_t operator()() const override;
    void operator()(int a) override;

  private:
    size_t count_;
    int prev_;
    bool is_first_;
  };
}

#endif

#ifndef KRIVOSHAPOV_INC_SEQ_HPP
#define KRIVOSHAPOV_INC_SEQ_HPP

#include "itrait.hpp"

namespace krivoshapov {
  struct IncSeq: ITrait {
    IncSeq();
    size_t operator()() const override;
    void operator()(int a) override;

  private:
    size_t count_;
    int prev_;
  };
}

#endif

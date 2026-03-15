#ifndef KRIVOSHAPOV_INC_SEQ_HPP
#define KRIVOSHAPOV_INC_SEQ_HPP

#include <limits>

#include "itrait.hpp"

namespace krivoshapov {
  struct IncSeq: ITrait {
    IncSeq():
      count_(0),
      prev_(std::numeric_limits< int >::max())
    {}

  private:
    size_t count_;
    int prev_;

    void upd(int a) override;
    size_t result() const override;
    const char* name() const override;
  };
}

#endif

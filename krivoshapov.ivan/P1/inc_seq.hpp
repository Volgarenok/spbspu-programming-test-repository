#ifndef KRIVOSHAPOV_INC_SEQ_HPP
#define KRIVOSHAPOV_INC_SEQ_HPP

#include "itrait.hpp"

namespace krivoshapov
{
  struct IncSeq : ITrait
  {
    IncSeq() : count_(0),
               prev_(0),
               n_(0)
    {
    }

  private:
    size_t count_;
    int prev_;
    size_t n_;

    void upd(int a) override;
    size_t result() const override;
    const char *name() const override;
  };
}

#endif

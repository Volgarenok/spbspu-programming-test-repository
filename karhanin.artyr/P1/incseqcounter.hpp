#ifndef KARHANIN_INSEQCOUNTER_HPP
#define KARHANIN_INSEQCOUNTER_HPP

#include "itrait.hpp"

namespace karhanin
{
  class IncSeqCounter : public ITrait
  {
  public:
    IncSeqCounter();
    void operator()(int value) override;
    int operator()() const override ;
  };
}
#endif

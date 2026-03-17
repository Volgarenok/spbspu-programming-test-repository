#ifndef KARHANIN_EVENSEQCOUNTER_HPP
#define KARHANIN_EVENSEQCOUNTER_HPP

#include "itrait.hpp"

namespace karhanin
{
  class EvenSeqCounter : public ITrait
  {
    int curCount;
  public:
    EvenSeqCounter();
    void operator()(int value) override;
    int operator()() const override;
  };
}
#endif
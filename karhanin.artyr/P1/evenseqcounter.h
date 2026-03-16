#pragma once
#include "itrait.h"

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
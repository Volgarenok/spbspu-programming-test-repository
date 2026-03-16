#pragma once
#include "itrait.h"

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
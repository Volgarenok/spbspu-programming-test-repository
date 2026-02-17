#ifndef NOVIKOV_CNTMAX_HPP
#define NOVIKOV_CNTMAX_HPP

#include "iTrait.hpp"

namespace novikov
{
  class cnt_max: public ITrait
  {
  private:
    size_t counter = 0;
    int biggest = 0;
    size_t res = 0;

  public:
    size_t operator()() const override;
    void operator()(int num) override;
  };
}
#endif

#ifndef NOVIKOV_CNTMAX_HPP
#define NOVIKOV_CNTMAX_HPP

#include "iTrait.hpp"

namespace novikov
{
  class cnt_max: public ITrait
  {
  private:
    size_t counter;
    int biggest;
    size_t res;

  public:
    cnt_max();
    size_t operator()() const override;
    void operator()(int num) override;
  };
}
#endif

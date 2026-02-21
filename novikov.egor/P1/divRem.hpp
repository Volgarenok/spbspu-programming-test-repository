#ifndef NOVIKOV_DIVREM_HPP
#define NOVIKOV_DIVREM_HPP

#include "iTrait.hpp"

namespace novikov
{
  class div_rem: public ITrait
  {
  private:
    bool is_first_try;
    int late_num;
    size_t res;

  public:
    div_rem();
    size_t operator()() const override;
    void operator()(int num) override;
  };
}
#endif

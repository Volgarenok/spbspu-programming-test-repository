#ifndef NOVIKOV_DIVREM_HPP
#define NOVIKOV_DIVREM_HPP

#include "iTrait.hpp"

namespace novikov
{
  class div_rem: public ITrait
  {
  private:
    bool is_first_try = true;
    int late_num = 0;
    size_t res = 0;

  public:
    size_t operator()() const override;
    void operator()(int num) override;
  };
}
#endif
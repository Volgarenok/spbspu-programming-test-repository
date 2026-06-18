#ifndef CNT_MAX_HPP
#define CNT_MAX_HPP

#include "i_trait.hpp"

namespace khvaevskiy
{
  class cnt_max: public i_trait
  {
  private:
    std::size_t count_;
    long long max_val_;
    std::size_t result_;

  public:
    cnt_max();
    std::size_t operator()() const override;
    void operator()(long long num) override;
  };
}

#endif

#ifndef AFT_MAX_HPP
#define AFT_MAX_HPP

#include "i_trait.hpp"

namespace khvaevskiy
{
  class aft_max: public i_trait
  {
  private:
    std::size_t count_;
    long long max_val_;
    std::size_t max_pos_;
    std::size_t result_;
    bool max_found_;

  public:
    aft_max();
    std::size_t operator()() const override;
    void operator()(long long num) override;
    void finalize();
  };
}

#endif

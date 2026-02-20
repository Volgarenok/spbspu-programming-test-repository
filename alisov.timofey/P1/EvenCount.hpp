#ifndef ALISOV_EVENCOUNT_HPP
#define ALISOV_EVENCOUNT_HPP

#include "ITrait.hpp"

namespace alisov
{
  struct EvenCount final: ITrait
  {
    EvenCount();

    void operator()(int a) override;
    int operator()() const override;

  private:
    int current_;
    int max_;
  };
}

#endif
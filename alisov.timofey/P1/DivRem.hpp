#ifndef ALISOV_DIVREM_HPP
#define ALISOV_DIVREM_HPP

#include "ITrait.hpp"
#include <iostream>

namespace alisov
{
  struct DivRem final: ITrait
  {
    DivRem();

    void operator()(int a) override;
    int operator()() const override;

  private:
    size_t count_;
    int total_;
    int prev_;
  };
}

#endif
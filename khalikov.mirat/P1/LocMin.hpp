#ifndef LOCMIN_HPP
#define LOCMIN_HPP

#include "ITrait.hpp"
#include <iostream>

namespace khalikov
{
  struct LocMin final : ITrait
  {
    LocMin();
    void operator()(int a) override;
    int operator()() override;
  private:
    size_t count_;
    int res_;
    int prev_;
    int act_;
    int next_;
  };
}

#endif

#ifndef LOCMIN_HPP
#define LOCMIN_HPP

#include "ITrait.hpp"
#include <iostream>

namespace khalikov
{
  struct LocMin
  {
    LocMin();
    void operator()(int a);
    int operator()();
  private:
    size_t c_;
    int k_;
    int prev_;
    int act_;
    int next_;
  };
}

#endif

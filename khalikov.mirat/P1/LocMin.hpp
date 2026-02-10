#ifndef LOCMIN_HPP
#define LOCMIN_HPP

#include "ITrait.hpp"

namespace khalikov
{
  struct LocMin: ITrait
  {
    LocMin();
    void operator()(int a);
    int operator()();
    private:
      bool firstadd_;
      int k_;
      int prev_;
      int act_;
      int next_;
  };
}

#endif

#ifndef SIZE_HPP
#define SIZE_HPP
#include "ITrait.hpp"

namespace khalikov
{
  struct Size: ITrait
  {
    Size();
    void operator()(int a);
    int operator()();
    private:
      int k_;
  };
}

#endif

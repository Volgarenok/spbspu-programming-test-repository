#include "aftMax.hpp"
#include <iostream>
namespace karpenkov {
  aftMax::aftMax():
  afterMax(0),
  maxNumber(std::numeric_limits<int>::min())
  {}
  void aftMax::process(int num){
    if (maxNumber < number) {
      maxNumber = number;
      afterMax = 0;
    } else {
      afterMax++;
    }
  }
  size_t aftMax::res(){
    return afterMax;
  }
}

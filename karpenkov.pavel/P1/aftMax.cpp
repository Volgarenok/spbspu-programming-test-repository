#include "aftMax.hpp"
#include <iostream>
#include <limits>
namespace karpenkov {
  AftMax::AftMax():
  afterMax(0),
  maxNumber(std::numeric_limits<int>::min())
  {}
  void AftMax::process(int num){
    if (maxNumber < num) {
      maxNumber = num;
      afterMax = 0;
    } else {
      afterMax++;
    }
  }
  size_t AftMax::res() const{
    return afterMax;
  }
}

#include "aftMax.hpp"
#include <iostream>
#include <limits>

  karpenkov::AftMax::AftMax():
  afterMax(0),
  maxNumber(std::numeric_limits<int>::min()),
  count(0)
  {}
  void karpenkov::AftMax::process(int num){
    count++;
    if (maxNumber < num) {
      maxNumber = num;
      afterMax = 0;
    } else {
      afterMax++;
    }
  }
  size_t karpenkov::AftMax::res() const{
    if (count < 2) {
      throw std::logic_error("Not enough arguments for aftMax");
    }
    return afterMax;
  }
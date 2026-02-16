#include "signChange.hpp"
#include <iostream>
namespace karpenkov{
  signChange::signChange():
    count(0),
    currentSign(0),
    previousSign(0),
    isFirstNum(true)
    {}
  void signChange::process(int num){
    if(isFirstNum){
      isFirstNum = false;
    }
    else{
      currentSign = (num > 0) ? 1 : -1;
      if (!isFirstnum && currentSign != previousSign) {
        count++;
      }
      previousSign = currentSign;
    }
  }
  size_t signChange::res(){
    return count;
  }
}
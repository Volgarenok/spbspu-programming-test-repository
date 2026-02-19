#include "signChange.hpp"
#include <iostream>
karpenkov::SignChange::SignChange():
  count(0),
  currentSign(0),
  previousSign(0),
  isFirstNum(true)
 {}
void karpenkov::SignChange::process(int num){
  if(isFirstNum) {
    isFirstNum = false;
    previousSign = (num > 0) ? 1 : -1;
  }
  else{
    currentSign = (num > 0) ? 1 : -1;
    if (!isFirstNum && currentSign != previousSign) {
      count++;
    }
    previousSign = currentSign;
  }
}
size_t karpenkov::SignChange::res() const{
  return count;
}

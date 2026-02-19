#include <iostream>
#include "aftMax.hpp"
#include "signChange.hpp"

int main()
{
  karpenkov::AftMax aft;
  karpenkov::SignChange signChange;
  karpenkov::ISeqProperty* properties [] = {&aft, &signChange};
  int number;
  size_t countNum = 0;
  while (std::cin >> number && number != 0){
    std::cin >> number;
    if (number == 0) {
      break;
    }
    countNum++;
    for (size_t i = 0; i < 2; i++) {
      if (countNum == 0 && i == 1) {
        std::cerr << "Not enough numbers for AFT-MAX" << '\n';
        return 2;
      }
      (*properties[i])(number);
    }
  }
  if (!std::cin && !std::cin.eof()) {
    std::cerr << "Invalid input" << '\n';
    return 1;
  }
  try {
    std::cout << aft() << '\n';
  }
  catch (const std::logic_error& e) {
    std::cerr << e.what() << '\n';
    return 2;
  }
  std::cout << signChange() << '\n';
}

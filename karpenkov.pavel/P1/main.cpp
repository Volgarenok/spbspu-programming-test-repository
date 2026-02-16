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
  while (true) {
    std::cin >> number;
    if (std::cin.fail()) {
      std::cerr << "Invalid input" << '\n';
      return 1;
    }
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
  std::cout << aft() << '\n';
  std::cout << signChange() << '\n';
}

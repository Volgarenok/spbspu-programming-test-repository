#include "sgn_chg.hpp"
#include "aft_max.hpp"
#include <iostream>

int main()
{
  lukashevich::SignChangeCount sgn_chg;
  lukashevich::AfterMaxCount aft_max;

  int num = 0;
  bool firstNum = true;

  while (std::cin >> num) {
    if (num == 0) {
      break;
    }
      sgn_chg.countSGN(num);
      aft_max.processNext(num);
  }

  if (std::cin.fail() && ! std::cin.eof()) {
    std::cerr << "error: input isn't number\n";
    return 1;
  }
  if (aft_max.hasMax()) {
    std::cout << aft_max.getCountAftMax() << "\n";
  }
  else {
    std::cerr << "error: sequence is empty, aft_max can't be counted\n";
  }

  std::cout << sgn_chg.getCount() << "\n";

  return 0;
}

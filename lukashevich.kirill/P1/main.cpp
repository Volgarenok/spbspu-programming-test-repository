#include "sgn_chg.hpp"
#include <iostream>

int main()
{
  lukashevich::signChangeCount sgn_chg;
  int num = 0;
  bool firstNum = true;
  
  while (std::cin >> num) {
    if (num == 0) {
      break;
    }
      sgn_chg.countSGN(num);
  }

  if (std::cin.fail() && ! std::cin.eof()) {
    std::cerr << "error: input isn't number\n";
    return 1;
  }

  std::cout << sgn_chg.get_count() << "\n";

  return 0;
}

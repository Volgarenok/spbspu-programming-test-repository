#include <iostream>

int main()
{
  int number, previousSign = -1;
  int maxNumber = std::numeric_limits<int>::min();
  size_t countNum = 0, changeCount = 0, afterMax = 0;
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
    if (maxNumber < number) {
      maxNumber = number;
      afterMax = 0;
    } else {
      afterMax++;
    }
    int currentSign = (number > 0) ? 1 : -1;
    if (countNum > 1 && currentSign != previousSign) {
      changeCount++;
    }
    previousSign = currentSign;
  }
  std::cout << changeCount << '\n';
  if (countNum == 0) {
    std::cerr << "Not enough numbers for AFT-MAX" << '\n';
    return 2;
  }
  std::cout << afterMax << '\n';
}

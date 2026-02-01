#include <iostream>

int main()
{
  int num, previousSign = -1;
  size_t countNum = 0, changeCount = 0;
  while (true) {
    std::cin >> num;
    if (std::cin.fail()) {
      std::cerr << "Invalid input" << '\n';
      return 1;
    }
    if (num == 0) {
      break;
    }
    countNum++;
    int currentSign = (num > 0) ? 1 : -1;
    if (countNum > 1 && currentSign != previousSign) {
      changeCount++;
    }
    previousSign = currentSign;
  }
  std::cout << changeCount << '\n';
}

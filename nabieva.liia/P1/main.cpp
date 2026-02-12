#include <iostream>
//CNT-MAX MON-DEC

int main()
{
  int a = 0;
  while (std::cin >> a) {
    if (a == 0) {
      break;
    }
  }
  if (!std::cin.eof() && std::cin.fail()) {
    std::cerr << "Error input";
    return 1;
  }
}

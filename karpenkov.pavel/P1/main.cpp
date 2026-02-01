#include <iostream>

int main()
{
  int num;
  while (true) {
    std::cin >> num;
    if (std::cin.fail()) {
      std::cerr << "Invalid input" << '\n';
      return 1;
    }
    if (num == 0) {
      break;
    }
  }
}

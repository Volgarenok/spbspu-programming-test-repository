#include <iostream>
#include "divRem.hpp"
#include "cntMax.hpp"

int main()
{
  novikov::div_rem d;
  novikov::cnt_max c;
  novikov::ITrait *traits[2];
  traits[0] = &d;
  traits[1] = &c;
  int num = 1;
  std::cin >> num;
  size_t counter = 0;
  while (!std::cin.fail()) {
    if (num == 0) {
      break;
    }
    counter++;
    d(num);
    c(num);
    std::cin >> num;
    if (std::cin.fail()) {
      std::cerr << "Bad sequence\n";
      return 1;
    }
  }
  if (counter == 1) {
    std::cerr << "Can't calculate div_rem. Sequence too short\n";
    std::cout << "cnt_max: " << c() << "\n";
    return 2;
  } else if (counter == 0) {
    std::cerr << "Can't calculate traits. Sequence too short\n";
    return 2;
  } else {
    for (int i = 0; i < 2; ++i) {
      std::cout << (*traits[i])() << "\n";
    }
  }
}

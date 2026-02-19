#include <iostream>
#include "divRem.hpp"
#include "cntMax.hpp"

int main()
{
  novikov::ITrait *traits[2];
  traits[0] = new novikov::div_rem();
  traits[1] = new novikov::cnt_max();

  int num = 0;
  size_t counter = 0;

  while (true) {
    std::cin >> num;

    if (std::cin.fail()) {
      std::cerr << "Bad sequence\n";
      for (int i = 0; i < 2; ++i) {
        delete traits[i];
      }
      return 1;
    }

    if (num == 0) {
      break;
    }

    counter++;
    for (int i = 0; i < 2; ++i) {
      (*traits[i])(num);
    }
  }

  if (counter == 0) {
    std::cerr << "Can't calculate traits. Sequence too short\n";
    for (int i = 0; i < 2; ++i) {
      delete traits[i];
    }
    return 2;
  }

  if (counter == 1) {
    std::cerr << "Can't calculate div_rem. Sequence too short\n";
    std::cout << "cnt_max: " << (*traits[1])() << "\n";

    for (int i = 0; i < 2; ++i) {
      delete traits[i];
    }
    return 2;
  }

  for (int i = 0; i < 2; ++i) {
    std::cout << (*traits[i])() << "\n";
  }

  for (int i = 0; i < 2; ++i) {
    delete traits[i];
  }

  return 0;
}

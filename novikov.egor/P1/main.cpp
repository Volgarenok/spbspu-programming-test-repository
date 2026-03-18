#include <iostream>
#include "divRem.hpp"
#include "cntMax.hpp"

void destroy(novikov::ITrait *traits[])
{
  delete traits[0];
  delete traits[1];
}

int main()
{
  novikov::ITrait *traits[2] = {nullptr, nullptr};
  try {
    traits[0] = new novikov::div_rem();
    traits[1] = new novikov::cnt_max();

  } catch (const std::bad_alloc&) {
    std::cerr << "Bad alloc\n";
    destroy(traits);
    return 2;
  }

  int num = 0;
  size_t counter = 0;

  while (true) {
    std::cin >> num;

    if (std::cin.fail()) {
      std::cerr << "Bad sequence\n";
      destroy(traits);
      return 1;
    }

    if (num == 0) {
      break;
    }

    counter++;
    for (size_t i = 0; i < 2; ++i) {
      (*traits[i])(num);
    }
  }

  if (counter == 0) {
    std::cerr << "Can't calculate traits. Sequence too short\n";
    destroy(traits);
    return 2;
  }

  if (counter == 1) {
    std::cerr << "Can't calculate div_rem. Sequence too short\n";
    std::cout << "cnt_max: " << (*traits[1])() << "\n";
    destroy(traits);
    return 2;
  }

  for (size_t i = 0; i < 2; ++i) {
    std::cout << (*traits[i])() << "\n";
  }
  destroy(traits);
  return 0;
}

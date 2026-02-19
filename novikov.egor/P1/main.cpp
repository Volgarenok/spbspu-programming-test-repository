#include <iostream>
#include "divRem.hpp"
#include "cntMax.hpp"
#include <memory>

int main()
{
  std::unique_ptr< novikov::ITrait > traits[2] = {std::make_unique< novikov::div_rem >(),
                                                  std::make_unique< novikov::cnt_max >()};
  int num = 0;
  size_t counter = 0;

  while (true) {
    std::cin >> num;

    if (std::cin.fail()) {
      std::cerr << "Bad sequence\n";
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
    return 2;
  }

  if (counter == 1) {
    std::cerr << "Can't calculate div_rem. Sequence too short\n";
    std::cout << "cnt_max: " << (*traits[1])() << "\n";
    return 2;
  }

  for (int i = 0; i < 2; ++i) {
    std::cout << (*traits[i])() << "\n";
  }
  
  return 0;
}

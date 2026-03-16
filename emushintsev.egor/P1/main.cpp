#include <iostream>
#include "pyth.hpp"
#include "max_elements.hpp"

int main()
{
  using namespace emushintsev;
  PythCount pythCounter;
  MaxElements maxFinder;
  int num = 0;
  while (std::cin >> num && num != 0)
  {
    pythCounter.processNext(num);
    maxFinder.processNext(num);
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Error: Invalid input\n";
    return 1;
  }

  std::cout << pythCounter.getCount() << "\n";

  if (maxFinder.hasTwo())
  {
    std::cout << maxFinder.getMax2() << " " << maxFinder.getMax1() << "\n";
  }
  else
  {
    std::cout << "0\n";
  }
  return 0;
}

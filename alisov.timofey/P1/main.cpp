#include <iostream>
#include "DivRem.hpp"
#include "EvenCount.hpp"

int main()
{
  alisov::ITrait *divrem = new alisov::DivRem();
  alisov::ITrait *evencnt = new alisov::EvenCount();

  int number = 0;

  while ((std::cin >> number) && (number != 0))
  {
    (*divrem)(number);
    (*evencnt)(number);
  }

  if (std::cin.fail())
  {
    std::cerr << "Input Error\n";
    delete divrem;
    delete evencnt;
    return 1;
  }

  try
  {
    std::cout << (*divrem)() << '\n';
  }
  catch (const std::exception &)
  {
    std::cerr << "Cant calculate\n";
    std::cout << 0 << '\n';
    std::cout << (*evencnt)() << '\n';

    delete divrem;
    delete evencnt;
    return 2;
  }

  std::cout << (*evencnt)() << '\n';

  delete divrem;
  delete evencnt;

  return 0;
}

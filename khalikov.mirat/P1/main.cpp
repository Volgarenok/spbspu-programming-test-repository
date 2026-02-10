#include <iostream>
#include "Size.hpp"
#include "GrtLss.hpp"
#include "LocMin.hpp"

int main()
{
  namespace khal = khalikov;
  int number = 0;
  int size = 0;
  khal::LocMin a;
  khal::GrtLss b;
  khal::Size c;
  try
  {
    while((std::cin >> number) && (number != 0))
    {
      a(number);
      b(number);
      c(number);
    }
    if (std::cin.fail())
    {
      std::cerr << "Seq is not read. Input Error" << "\n";
      return 1;
    }
    size = c();
  }
  catch (...)
  {
    std::cerr << "Seq is not read. Not enough numbers!" << "\n";
    return 2;
  }
    std::cout << "SIZE = " << size << "\n";
    std::cout << "LOCMIN = " << a() << "\n";
    std::cout << "GRTLSS = " << b() << "\n";
}

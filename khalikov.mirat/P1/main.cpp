#include <iostream>
#include "GrtLss.hpp"
#include "LocMin.hpp"

int main()
{
  namespace khal = khalikov;
  int number = 0;
  khal::LocMin a;
  khal::GrtLss b;
  while((std::cin >> number) && (number != 0))
  {
    a(number);
    b(number);
  }
  if (std::cin.fail())
  {
    std::cerr << "Seq is not read. Input Error" << "\n";
    return 1;
  }
  try
  {
    std::cout << "LOCMIN = " << a() << "\n";
    std::cout << "GRTLSS = " << b() << "\n";
  }
  catch (const std::runtime_error &)
  {
    std::cerr << "Seq is not read. Not enough numbers!" << "\n";
    return 2;
  }
}

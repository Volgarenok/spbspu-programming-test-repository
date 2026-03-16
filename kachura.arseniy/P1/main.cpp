#include <iostream>
#include <stdexcept>

#include "grt_lss.hpp"
#include "aft_max.hpp"

int main()
{
  kachura::GrtLss grt_lss;
  kachura::AftMax aft_max;

  int a = 0;
  while (std::cin >> a && a != 0)
  {
    grt_lss(a);
    aft_max(a);
  }

  if (!std::cin.eof() && std::cin.fail())
  {
    std::cerr << "Bad input\n";
    return 1;
  }

  try
  {
    std::cout << grt_lss.trait() << ": " << grt_lss() << "\n";
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << grt_lss.trait() << ": " << e.what() << "\n";
    return 2;
  }

  try
  {
    std::cout << aft_max.trait() << ": " << aft_max() << "\n";
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << aft_max.trait() << ": " << e.what() << "\n";
    return 2;
  }

  return 0;
}
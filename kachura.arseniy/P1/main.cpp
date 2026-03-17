#include <iostream>
#include "aft_max.hpp"
#include "grt_lss.hpp"

int main()
{
  kachura::AftMax info_max;
  kachura::GrtLss info_lss;
  int num;

  while(std::cin >> num && num != 0)
  {
    info_max.step(&num);
    info_lss.step(&num);
  }

  if(std::cin.fail() && !std::cin.eof())
  {
    std::cout << "Bad input!" << '\n';
    return 1;
  }

  try
  {
    std::cout << "Aft_Max: " << info_max.get_count() << '\n';
  }
  catch(const char * error)
  {
    std::cout << error << '\n';
    return 2;
  }

  try
  {
    std::cout << "Grt_Lss: " << info_lss.get_count() << '\n';
  }
  catch(const char * error)
  {
    std::cout << error << '\n';
    return 2;
  }

  return 0;
}

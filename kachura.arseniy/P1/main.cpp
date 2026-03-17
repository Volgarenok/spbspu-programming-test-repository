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

  std::cout << info_max.get_count() << '\n';
  std::cout << info_lss.get_count() << '\n';

  return 0;
}

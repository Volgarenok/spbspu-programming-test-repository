#include <iostream>
#include "properties.hpp"

int main()
{
  matveev::CntMaxProperty cnt_max;
  matveev::DivRemProperty div_rem;
  matveev::ISeqProperty* bim[2];
  bim[0] = &cnt_max;
  bim[1] = &div_rem;

  int a = 0;
  while (std::cin >> a && a != 0)
  {
    for (size_t i = 0; i < 2; ++i)
    {
      (*bim[i])(a);
    }
  }

  if (std::cin.fail())
  {
    std::cerr << "Error input\n";
    return 1;
  }

  try
  {
    std::cout << "CNT-MAX " << bim[0]->operator()() << '\n';
    std::cout << "DIV-REM " << bim[1]->operator()() << '\n';
  }
  catch (...)
  {
    std::cerr << "Error" << '\n';
    return 2;
  }

  return 0;
}

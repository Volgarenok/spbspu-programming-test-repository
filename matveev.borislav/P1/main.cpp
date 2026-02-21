#include "properties.hpp"
int main()
{
  matveev::ISeqProperty* bim[2];
  bim[0] = new matveev::CntMaxProperty();
  bim[1] = new matveev::DivRemProperty();

  int a;
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
    for (size_t i = 0; i < 2; ++i)
    {
      delete bim[i];
    }
    return 1;
  }

  try
  {
    std::cout << "CNT-MAX " << bim[0]->operator()() << '\n';
    std::cout << "DIV-REM " << bim[1]->operator()() << '\n';
  }
  catch (const std::logic_error& e)
  {
    std::cerr << "Error" << '\n';
    for (size_t i = 0; i < 2; ++i)
    {
      delete bim[i];
    }
    return 2;
  }

  for (size_t i = 0; i < 2; ++i)
  {
    delete bim[i];
  }

  return 0;
}

#include <iostream>
#include <stdexcept>
#include "sub_max.hpp"
#include "aft_max.hpp"

int main()
{
  sadovnik::SubMaxCount sub;
  sadovnik::AftMaxCount aft;

  int x;

  while (std::cin >> x)
  {
    if (x == 0)
    {
      break;
    }
    sub(x);
    aft(x);
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "bad input\n";
    return 1;
  }
  if (std::cin.eof())
  {
    std::cerr << "no zero\n";
    return 1;
  }

  int err = 0;

  try
  {
    std::cout << sub() << '\n';
  }
  catch (const std::exception&)
  {
    std::cerr << "not enough numbers\n";
    err = 2;
  }

  std::cout << aft() << '\n';

  return err;
}

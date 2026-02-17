#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "incseq.hpp"
#include "aftermax.hpp"

int main()
{
  try
  {
    shevchenko::IncSeq incSeq;
    shevchenko::AfterMax afterMax;

    int a = 0;
    bool hasNumbers = false;

    while (std::cin >> a)
    {
      if (a == 0) break;
      hasNumbers = true;
      incSeq(a);
      afterMax(a);
    }

    if (!std::cin.eof())
    {
      std::cerr << "bad input\n";
      return 1;
    }

    if (!hasNumbers)
    {
      return 2;
    }

    std::cout << incSeq() << "\n";
    std::cout << afterMax() << "\n";

    return 0;

  }
  catch (const std::exception& e)
  {
    std::cerr << "error\n";
    return 1;
  }
}

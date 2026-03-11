#include "inc_seq.hpp"
#include "div_rem.hpp"

#include <iostream>
#include <stdexcept>

int main()
{
  krivoshapov::IncSeq inc_seq;
  krivoshapov::DivRem div_rem;

  try
  {
    int a = 0;
    while (std::cin >> a)
    {
      if (a == 0)
      {
        break;
      }
      inc_seq(a);
      div_rem(a);
    }

    if (!std::cin.eof() && std::cin.fail())
    {
      throw std::invalid_argument("Bad input");
    }

    std::cout << inc_seq.trait() << ": " << inc_seq() << "\n";
    std::cout << div_rem.trait() << ": " << div_rem() << "\n";
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (const std::runtime_error &e)
  {
    std::cerr << div_rem.trait() << ": " << e.what() << "\n";
    std::cout << inc_seq.trait() << ": " << inc_seq() << "\n";
    return 2;
  }

  return 0;
}

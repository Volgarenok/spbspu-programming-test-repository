#include <iostream>
#include <stdexcept>

#include "inc_seq.hpp"
#include "div_rem.hpp"

int main()
{
  krivoshapov::IncSeq inc_seq;
  krivoshapov::DivRem div_rem;

  int a = 0;
  while (std::cin >> a && a != 0)
  {
    inc_seq(a);
    div_rem(a);
  }

  if (!std::cin.eof() && std::cin.fail())
  {
    std::cerr << "Bad input\n";
    return 1;
  }

  std::cout << inc_seq.trait() << ": " << inc_seq() << "\n";

  try
  {
    std::cout << div_rem.trait() << ": " << div_rem() << "\n";
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << div_rem.trait() << ": " << e.what() << "\n";
    return 2;
  }

  return 0;
}

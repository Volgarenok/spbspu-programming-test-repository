#include <iostream>

#include "inc_seq.hpp"
#include "div_rem.hpp"

void destroy(krivoshapov::ITrait* traits[])
{
  delete traits[0];
  delete traits[1];
}

int main()
{
  krivoshapov::ITrait* traits[2] = {nullptr, nullptr};
  try
  {
    traits[0] = new krivoshapov::IncSeq();
    traits[1] = new krivoshapov::DivRem();
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Bad alloc\n";
    destroy(traits);
    return 2;
  }

  int a = 0;
  size_t counter = 0;
  while (std::cin >> a && a != 0)
  {
    ++counter;
    for (size_t i = 0; i < 2; ++i)
    {
      (*traits[i])(a);
    }
  }

  if (!std::cin.eof() && std::cin.fail())
  {
    std::cerr << "Bad input\n";
    destroy(traits);
    return 1;
  }

  if (counter < 2)
  {
    std::cerr << "div-rem: sequence is too short\n";
    std::cout << "inc-seq: " << (*traits[0])() << "\n";
    destroy(traits);
    return 2;
  }

  std::cout << "inc-seq: " << (*traits[0])() << "\n";
  std::cout << "div-rem: " << (*traits[1])() << "\n";

  destroy(traits);
  return 0;
}

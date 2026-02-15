#include <iostream>
#include "count.hpp"
#include "aftMax.hpp"
#include "cntMin.hpp"

int main()
{
  lachugin::Count k;
  lachugin::AftMax max;
  lachugin::CntMin min;
  lachugin::SeqProperty* props[] = { &max, &min, &k };

  int n = 0;

  while (std::cin >> n && n != 0)
  {
    for (auto* p : props)
    {
      (*p)(n);
    }
  }

  if (!std::cin && !std::cin.eof())
  {
    std::cerr << "Error: invalid input sequence\n";
    return 1;
  }

  try
  {
    k();
    std::cout << max() << "\n" << min();
  }
  catch (...)
  {
    std::cout << "Error: insufficient sequence length\n";
    return 2;
  }
}

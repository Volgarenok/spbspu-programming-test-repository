#include <iostream>
#include "aftMax.hpp"
#include "cntMin.hpp"

int main()
{
  lachugin::SeqProperty* propertys[2];

  propertys[0] = new lachugin::AftMax();
  propertys[1] = new lachugin::CntMin();

  int n = 0;
  while (std::cin >> n && n != 0)
  {
    for (size_t i = 0; i < 2; ++i)
    {
      (*propertys[i])(n);
    }
  }

  if (!std::cin && !std::cin.eof())
  {
    std::cerr << "Error: invalid input sequence\n";
    for (size_t i = 0; i < 2; ++i)
    {
      delete[] propertys[i];
    }
    return 1;
  }

  try
  {
    for (size_t i = 0; i < 2; ++i)
    {
      std::cout << (*propertys[i])() << "\n";
    }
  }
  catch (const std::logic_error&)
  {
    std::cout << "Error: insufficient sequence length\n";
    for (size_t i = 0; i < 2; ++i)
    {
      delete[] propertys[i];
    }
    return 2;
  }
  for (size_t i = 0; i < 2; ++i)
  {
    delete[] propertys[i];
  }
}

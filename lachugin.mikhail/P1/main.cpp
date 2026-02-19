#include <iostream>
#include "aftMax.hpp"
#include "cntMin.hpp"

int main()
{
  lachugin::SeqProperty* propertys[2];

  propertys[0] = new lachugin::AftMax();
  propertys[1] = nullptr;
  try
  {
    propertys[1] = new lachugin::CntMin();
  }
  catch (const std::bad_alloc&)
  {
    delete propertys[0];
    return 1;
  }

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
    lachugin::deletePropertys(propertys, 2);
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
    lachugin::deletePropertys(propertys, 2);
    return 2;
  }
  lachugin::deletePropertys(propertys, 2);
}

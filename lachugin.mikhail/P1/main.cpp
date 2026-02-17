#include <iostream>
#include "aftMax.hpp"
#include "cntMin.hpp"
#include "props.hpp"

int main()
{
  lachugin::AftMax max;
  lachugin::CntMin min;
  lachugin::SeqProperty* propertys[lachugin::property];
  lachugin::props(propertys, max, min);

  int n = 0;
  while (std::cin >> n && n != 0)
  {
    for (size_t i = 0; i < lachugin::property; ++i)
    {
      propertys[i]->operator()(n);
    }
  }

  if (!std::cin && !std::cin.eof())
  {
    std::cerr << "Error: invalid input sequence\n";
    return 1;
  }

  try
  {
    for (size_t i = 0; i < lachugin::property; ++i)
    {
      std::cout << propertys[i]->operator()() << "\n";
    }
  }
  catch (const std::logic_error&)
  {
    std::cout << "Error: insufficient sequence length\n";
    return 2;
  }
}

#include <iostream>
#include "traits.hpp"

int main()
{
  int el = 0;
  traits::ITrait *traitArray[2];
  traits::traitCreate(traitArray);
  while (std::cin >> el && el != 0)
  {
    traitArray[1]->operator()(el);
    traitArray[0]->operator()(el);
  }
  if (std::cin.fail())
  {
    std::cerr << "Input failed\n";
    return 1;
  }
  try
  {
    std::cout << traitArray[0]->operator()() << "\n";
    std::cout << traitArray[1]->operator()() << "\n";
    delete traitArray[0];
    delete traitArray[1];
    return 0;
  }
  catch (std::logic_error &error)
  {
    std::cout << error.what() << "\n";
    delete traitArray[0];
    delete traitArray[1];
    return 2;
  }
}

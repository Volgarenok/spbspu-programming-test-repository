#include <iostream>
#include "traits.hpp"

int main()
{
  int el = 0;
  size_t err = 0;
  traits::ITrait *traitArray[2];
  traits::traitCreate(traitArray);
  while (std::cin >> el && el != 0)
  {
    (*traitArray[1])(el);
    (*traitArray[0])(el);
  }
  if (std::cin.fail())
  {
    std::cerr << "Input failed\n";
    err = 1;
  }
  try
  {
    std::cout << (*traitArray[0])() << "\n";
    std::cout << (*traitArray[1])() << "\n";
  }
  catch (const std::logic_error &error)
  {
    std::cout << error.what() << "\n";
    err = 2;
  }
  delete traitArray[0];
  delete traitArray[1];
  return err;
}

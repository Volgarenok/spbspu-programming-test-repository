#include <iostream>
#include "GrtLss.hpp"
#include "LocMin.hpp"
#include "ITrait.hpp"

int main()
{
  namespace khal = khalikov;
  int number = 0;
  const size_t SIZE = 2;
  khal::ITrait ** traits = new khal::ITrait * [SIZE];
  traits[0] = new khal::LocMin();
  traits[1] = new khal::GrtLss();
  while((std::cin >> number) && (number != 0))
  {
    for (size_t i = 0; i < SIZE; i++)
    {
      (*traits[i])(number);
    }
  }

  if (std::cin.fail())
  {
    std::cerr << "Seq is not read. Input Error" << "\n";
    for (size_t i = 0; i < SIZE; i++)
    {
      delete traits[i];
    }
    delete[] traits;
    return 1;
  }
  try
  {
    for (size_t i = 0; i < SIZE; i++)
    {
      std::cout << (*traits[i])() << "\n";
    }
  }
  catch (const std::runtime_error &)
  {
    std::cerr << "Seq is not read. Not enough numbers!" << "\n";
    for (size_t i = 0; i < SIZE; i++)
    {
      delete traits[i];
    }
    delete[] traits;
    return 2;
  }
  for (size_t i = 0; i < SIZE; i++)
    {
      delete traits[i];
    }
    delete[] traits;
}

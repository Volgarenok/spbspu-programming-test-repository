#include "numeric_sequence.hpp"
#include <iostream>

int main()
{
  gordejchik::EvenCount evenCount;

  gordejchik::LocalMax localMax;

  gordejchik::ErrorStatus error;

  std::cout << "Enter sequence:\n";
  if (!gordejchik::processInput(evenCount, localMax, error))
  {
    return 1;
  }

  gordejchik::printResults(evenCount, localMax, error);

  if (error.foundError)
  {
    return 2;
  }

  return 0;
}

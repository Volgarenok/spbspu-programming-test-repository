#include "numeric_sequence.hpp"
#include <iostream>

int main()
{
  gordejchik::EvenCount evenCount;
  gordejchik::LocalMax localMax;

  std::cout << "Enter sequence:\n";

  int currentNumber = 0;
  while (std::cin >> currentNumber && currentNumber != 0)
  {
    evenCount.update(currentNumber);
    localMax.update(currentNumber);
  }

  if (std::cin.fail())
  {
    std::cerr << "Error: sequence contains non-numeric characters\n";
    return 1;
  }
  
  if (std::cin.eof() && currentNumber != 0)
  {
    std::cerr << "Error: sequence doesn't end with a zero\n";
    return 1;
  }

  gordejchik::printResults(evenCount, localMax);

  return 0;
}

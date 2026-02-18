#include "numeric_sequence.hpp"
#include <iostream>
#include <limits>

gordejchik::EvenCount::EvenCount()
{
  maxEvenCount = 0;
  currentEvenCount = 0;
  totalNumbers = 0;
}

void gordejchik::EvenCount::update(int number)
{
  if (number % 2 == 0)
  {
    ++currentEvenCount;
    if (currentEvenCount > maxEvenCount)
    {
      maxEvenCount = currentEvenCount;
    }
  }
  else
  {
    currentEvenCount = 0;
  }
  ++totalNumbers;
}

size_t gordejchik::EvenCount::getResult() const
{
  return maxEvenCount;
}

gordejchik::LocalMax::LocalMax()
{
  localMaxCount = 0;
  previousNumber = std::numeric_limits< int >::max();
  currentNumber = std::numeric_limits< int >::max();
  nextNumber = std::numeric_limits< int >::max();
  totalNumbers = 0;
}

void gordejchik::LocalMax::update(int number)
{
  nextNumber = number;
  if (currentNumber > previousNumber && currentNumber > nextNumber)
  {
    ++localMaxCount;
  }
  previousNumber = currentNumber;
  currentNumber = nextNumber;
  ++totalNumbers;
}

size_t gordejchik::LocalMax::getResult() const
{
  if (totalNumbers == 0)
  {
    throw "Error: sequence too short for LOC-MAX";
  }
  return localMaxCount;
}

void gordejchik::printResults(const gordejchik::EvenCount& evenCount, const gordejchik::LocalMax& localMax)
{
  std::cout << "Results:\n";

  std::cout << "EVN-CNT: " << evenCount.getResult() << '\n';

  try
  {
    std::cout << "LOC-MAX: " << localMax.getResult() << '\n';
  }
  catch (const char* e)
  {
    std::cerr << e << '\n';
  }
}

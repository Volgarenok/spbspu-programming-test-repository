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

gordejchik::ErrorStatus::ErrorStatus()
{
  foundError = false;
  foundZero = false;
}

void gordejchik::printError(const char* message, gordejchik::ErrorStatus& error)
{
  std::cerr << message << '\n';
  error.foundError = true;
}

bool gordejchik::processInput(gordejchik::EvenCount& evenCount, gordejchik::LocalMax& localMax, gordejchik::ErrorStatus& error)
{
  int currentNumber = 0;
  while (true)
  {
    std::cin >> currentNumber;
    if (std::cin.fail())
    {
      printError("Error: sequence contains non-numeric characters", error);
      return false;
    }
    if (std::cin.eof())
    {
      printError("Error: sequence doesn't end with a zero", error);
      return false;
    }
    if (currentNumber == 0)
    {
      error.foundZero = true;
      break;
    }
    evenCount.update(currentNumber);
    localMax.update(currentNumber);
  }
  return true;
}

void gordejchik::printResults(const gordejchik::EvenCount& evenCount, const gordejchik::LocalMax& localMax, gordejchik::ErrorStatus& error)
{
  std::cout << "Results:\n";

  std::cout << "EVN-CNT: " << evenCount.getResult() << '\n';

  try
  {
    std::cout << "LOC-MAX: " << localMax.getResult() << '\n';
  }
  catch (const char* e)
  {
    printError(e, error);
  }
}

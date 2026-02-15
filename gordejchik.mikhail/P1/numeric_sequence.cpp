#include "numeric_sequence.hpp"
#include <iostream>
#include <limits>

namespace gordejchik
{
  EvenCount::EvenCount()
  {
    maxEvenCount = 0;
    currentEvenCount = 0;
    totalNumbers = 0;
  }

  void EvenCount::update(int number)
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

  size_t EvenCount::getResult() const
  {
    return maxEvenCount;
  }

  LocalMax::LocalMax()
  {
    localMaxCount = 0;
    previousNumber = std::numeric_limits<int>::min();
    currentNumber = std::numeric_limits<int>::min();
    nextNumber = std::numeric_limits<int>::min();
    totalNumbers = 0;
  }

  void LocalMax::update(int number)
  {
    if (totalNumbers == 0)
    {
      previousNumber = number;
    }
    else if (totalNumbers == 1)
    {
      currentNumber = number;
    }
    else
    {
      nextNumber = number;
      if (currentNumber > previousNumber && currentNumber > nextNumber)
      {
        ++localMaxCount;
      }
      previousNumber = currentNumber;
      currentNumber = nextNumber;
    }
    ++totalNumbers;
  }

  size_t LocalMax::getResult() const
  {
    if (totalNumbers == 0)
    {
      throw "Error: sequence too short for LOC-MAX";
    }
    return localMaxCount;
  }

  ErrorStatus::ErrorStatus()
  {
    foundError = false;
    foundZero = false;
  }

  void printError(const char* message, ErrorStatus& error)
  {
    std::cerr << message << '\n';
    error.foundError = true;
  }

  bool processInput(EvenCount& evenCount, LocalMax& localMax, ErrorStatus& error)
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

  void printResults(const EvenCount& evenCount, const LocalMax& localMax, ErrorStatus& error)
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
}

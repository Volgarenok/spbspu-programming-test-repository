#include <iostream>

namespace gordejchik
{

  struct EvenCount
  {
    size_t maxEvenCount;
    size_t currentEvenCount;
    size_t totalNumbers;
  };

  struct LocalMax
  {
    size_t localMaxCount;
    int previousNumber;
    int currentNumber;
    int nextNumber;
    size_t totalNumbers;
    bool hasPrevious;
    bool hasCurrent;
  };

  struct ErrorStatus
  {
    bool foundError;
    bool foundZero;
  };

  bool readInteger(int& output)
  {
    std::cin >> output;
    return !std::cin.fail();
  }

  void printError(const char* message, ErrorStatus& error)
  {
    std::cerr << message << '\n';
    error.foundError = true;
  }

  void updateEvenCount(EvenCount& evenCount, int number)
  {
    if (number % 2 == 0)
    {
      ++evenCount.currentEvenCount;
      if (evenCount.currentEvenCount > evenCount.maxEvenCount)
      {
        evenCount.maxEvenCount = evenCount.currentEvenCount;
      }
    }
    else
    {
      evenCount.currentEvenCount = 0;
    }
    ++evenCount.totalNumbers;
  }

  void updateLocalMax(LocalMax& localMax, int number)
  {
    if (!localMax.hasPrevious)
    {
      localMax.previousNumber = number;
      localMax.hasPrevious = true;
    }
    else if (!localMax.hasCurrent)
    {
      localMax.currentNumber = number;
      localMax.hasCurrent = true;
    }
    else
    {
      localMax.nextNumber = number;
      if (localMax.currentNumber > localMax.previousNumber && localMax.currentNumber > localMax.nextNumber)
      {
        ++localMax.localMaxCount;
      }
      localMax.previousNumber = localMax.currentNumber;
      localMax.currentNumber = localMax.nextNumber;
    }
  }

  bool processInput(EvenCount& evenCount, ErrorStatus& error)
  {
    int currentNumber = 0;
    while (true)
    {
      if (!readInteger(currentNumber))
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
      updateEvenCount(evenCount, currentNumber);
    }
    return true;
  }

  void printResults(const EvenCount& evenCount)
  {
    std::cout << "Results:\n";
    if (evenCount.totalNumbers >= 1)
    {
      std::cout << "EVN-CNT: " << evenCount.maxEvenCount << '\n';
    }
    else
    {
      std::cout << "EVN-CNT: " << "0\n";
    }
  }
}

int main()
{
  gordejchik::EvenCount evenCount{};
  evenCount.maxEvenCount = 0;
  evenCount.currentEvenCount = 0;

  gordejchik::ErrorStatus error{};
  error.foundError = false;
  error.foundZero = false;

  std::cout << "Enter sequence:\n";
  if (!gordejchik::processInput(evenCount, error))
  {
    return 1;
  }

  gordejchik::printResults(evenCount);
  
  if (error.foundError)
  {
    return 2;
  }

  return 0;
}

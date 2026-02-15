#include <iostream>
#include <limits>

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
  };

  struct ErrorStatus
  {
    bool foundError;
    bool foundZero;
  };

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
    if (localMax.totalNumbers == 0)
    {
      localMax.previousNumber = number;
    }
    else if (localMax.totalNumbers == 1)
    {
      localMax.currentNumber = number;
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
    ++localMax.totalNumbers;
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
      updateEvenCount(evenCount, currentNumber);
      updateLocalMax(localMax, currentNumber);
    }
    return true;
  }

  void printResults(const EvenCount& evenCount, const LocalMax& localMax, ErrorStatus& error)
  {
    std::cout << "Results:\n";

    if (evenCount.totalNumbers >= 1)
    {
      std::cout << "EVN-CNT: " << evenCount.maxEvenCount << '\n';
    }
    else
    {
      std::cout << "EVN-CNT: 0\n";
    }

    if (localMax.totalNumbers == 0)
    {
      printError("Error: sequence too short for LOC-MAX", error);
      return;
    }

    if (evenCount.totalNumbers >= 3)
    {
      std::cout << "LOC-MAX: " << localMax.localMaxCount << '\n';
    }
    else
    {
      std::cout << "LOC-MAX: 0\n";
    }
  }
}

int main()
{
  gordejchik::EvenCount evenCount{};
  evenCount.maxEvenCount = 0;
  evenCount.currentEvenCount = 0;
  evenCount.totalNumbers = 0;

  gordejchik::LocalMax localMax{};
  localMax.localMaxCount = 0;
  localMax.previousNumber = std::numeric_limits<int>::min();
  localMax.currentNumber = std::numeric_limits<int>::min();
  localMax.nextNumber = std::numeric_limits<int>::min();

  gordejchik::ErrorStatus error{};
  error.foundError = false;
  error.foundZero = false;

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

#include <iostream>
#include <limits>

namespace gordejchik
{

  struct EvenCount
  {
    size_t maxEvenCount;
    size_t currentEvenCount;
    size_t totalNumbers;

    void update(int number)
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

    size_t getRes() const
    {
      return maxEvenCount;
    }
  };

  struct LocalMax
  {
    size_t localMaxCount;
    int previousNumber;
    int currentNumber;
    int nextNumber;
    size_t totalNumbers;

    void update(int number)
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

    size_t getRes() const
    {
      if (totalNumbers < 3)
      {
        throw "Error: sequence too short for LOC-MAX";
      }
      return localMaxCount;
    }
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

    std::cout << "EVN-CNT: " << evenCount.getRes() << '\n';

    try
    {
      std::cout << "LOC-MAX: " << localMax.getRes() << '\n';
    }
    catch (const char* e)
    {
      printError(e, error);
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

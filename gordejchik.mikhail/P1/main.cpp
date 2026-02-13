#include <iostream>

namespace gordejchik
{

  struct EvenCount
  {
    size_t maxEvenCount;
    size_t currentEvenCount;
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
}

int main()
{
  gordejchik::ErrorStatus error{};
  error.foundError = false;
  error.foundZero = false;

  return 0;
}

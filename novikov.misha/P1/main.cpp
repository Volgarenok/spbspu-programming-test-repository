#include <iostream>
namespace novikov
{
bool tryReadInteger(int& output){
    std::cin >> output;
    return !std::cin.fail();
}
void printError(const char* message){
    std::cerr << message << "\n";
}
}
int main()
{
    using namespace novikov;

    const char* const errorInvalidInput = "Ошибка: входные данные содержат нечисловые значения";
    const char* const errorNoZero = "Ошибка: не было введено число 0 для завершения";
    const char* const errorIncSeqShort = "Ошибка: последовательность слишком короткая";
    const char* const errorEvnCntShort = "Ошибка: Последовательность слишком короткая";

    std::size_t maxEvenChain = 0;
    std::size_t currentEvenChain = 0;
    std::size_t biggerCount = 0;
    std::size_t totalNumbers = 0;
    bool isFirst = true;
    bool hasError = false;
    bool foundZero = false;
    int currentNumber = 0;
    int previousNumber = 0;

    while (true) {
      if (!tryReadInteger(currentNumber)) {
        std::cerr << errorInvalidInput << '\n';
        return 1;
      }

      if (currentNumber == 0) {
        foundZero = true;
        break;
      }

      ++totalNumbers;

      if (!isFirst) {
        if (currentNumber > previousNumber) {
          ++biggerCount;
        }
      } else {
        isFirst = false;
      }

      previousNumber = currentNumber;
    }

    if (currentNumber % 2 == 0) {
        ++currentEvenChain;
        if (currentEvenChain > maxEvenChain) {
          maxEvenChain = currentEvenChain;
        }
      } else {
        currentEvenChain = 0;
      }
    }

    if (!foundZero) {
      std::cerr << errorNoZero << '\n';
      return 1;
    }

    if (totalNumbers == 0) {
      std::cout << "0\n";
      return 0;
    }

    if (totalNumbers >= 2) {
      std::cout << biggerCount << '\n';
    } else {
      std::cout << "0\n";
      printError(errorIncSeqShort);
      hasError = true;
    }

    if (totalNumbers >= 1) {
      std::cout << maxEvenChain << '\n';
    } else {
      std::cout << "0\n";
      printError(errorEvnCntShort);
      hasError = true;
    }

    if (hasError) {
      return 2;
    }

    return 0;

}

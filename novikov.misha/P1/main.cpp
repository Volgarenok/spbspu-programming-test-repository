#include <iostream>

namespace novikov {

struct Counter {
  size_t biggerCount;
  size_t totalNumbers;
  int previousNumber;
  bool isFirst;
};

struct EvenChain {
  size_t maxEvenChain;
  size_t currentEvenChain;
};

struct ErrorState {
  bool hasError;
  bool foundZero;
};

bool readInteger(int& output) {
  std::cin >> output;
  return !std::cin.fail();
}

void printError(const char* message, ErrorState& error) {
  std::cerr << message << '\n';
  error.hasError = true;
}

void updateCounter(Counter& counter, int number) {
  if (!counter.isFirst) {
    if (number > counter.previousNumber) {
      ++counter.biggerCount;
    }
  } else {
    counter.isFirst = false;
  }
  ++counter.totalNumbers;
  counter.previousNumber = number;
}

void updateEvenChain(EvenChain& evenChain, int number) {
  if (number % 2 == 0) {
    ++evenChain.currentEvenChain;
    if (evenChain.currentEvenChain > evenChain.maxEvenChain) {
      evenChain.maxEvenChain = evenChain.currentEvenChain;
    }
  } else {
    evenChain.currentEvenChain = 0;
  }
}

bool processInput(Counter& counter, EvenChain& evenChain, ErrorState& error) {
  int currentNumber = 0;

  while (true) {
    if (!readInteger(currentNumber)) {
      printError("Ошибка: Входные данные содержат нечисловые значения", error);
      return false;
    }

    if (std::cin.eof()) {
      printError("Ошибка: Не было введено число 0 для завершения", error);
      return false;
    }

    if (currentNumber == 0) {
      error.foundZero = true;
      break;
    }

    updateCounter(counter, currentNumber);
    updateEvenChain(evenChain, currentNumber);
  }

  return true;
}

void printResults(const Counter& counter, const EvenChain& evenChain, ErrorState& error) {
  if (counter.totalNumbers == 0) {
    std::cout << "0\n";
    std::cout << "0\n";
    return;
  }

  if (counter.totalNumbers >= 2) {
    std::cout << counter.biggerCount << '\n';
  } else {
    std::cout << "0\n";
    printError("Ошибка: последовательность слишком короткая для INC-SEQ", error);
  }

  if (counter.totalNumbers >= 1) {
    std::cout << evenChain.maxEvenChain << '\n';
  } else {
    std::cout << "0\n";
    printError("Ошибка: последовательность слишком короткая для EVN-CNT", error);
  }
}

}

int main() {
  novikov::Counter counter{};
  counter.biggerCount = 0;
  counter.totalNumbers = 0;
  counter.previousNumber = 0;
  counter.isFirst = true;

  novikov::EvenChain evenChain{};
  evenChain.maxEvenChain = 0;
  evenChain.currentEvenChain = 0;

  novikov::ErrorState error{};
  error.hasError = false;
  error.foundZero = false;

  if (!novikov::processInput(counter, evenChain, error)) {
    return 1;
  }

  novikov::printResults(counter, evenChain, error);

  if (error.hasError) {
    return 2;
  }

  return 0;
}

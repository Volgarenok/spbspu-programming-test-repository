#include <iostream>
#include <limits>

namespace yarmolinskaya {
  bool readNextValue(int &value);
  void updateMaxValues(int value, int &first, int &second);
  bool validateSequence(bool has_input, int second);
  int processSequence(int &first, int &second);
  void printError(int error_code);

}

namespace yarmolinskaya {
  bool readNextValue(int &value) {
    if (!(std::cin >> value)) {
      return false;
  }
    if (value == 0) {
      return false;
  }
  return true;
}
  int findSecondMax(int &first, int &second) {
    first = std::numeric_limits<int>::min();
    second = std::numeric_limits<int>::min();
    int value = 0;
    bool has_input = false;

    while (std::cin >> value) {
      if (value == 0) {
        break;
      }
      has_input = true;

      if (value > first) {
        second = first;
        first = value;
      } else if (value > second && value != first) {
        second = value;
      }
    }

    if (!std::cin.eof() && std::cin.fail()) {
      return 1;
    }

    if (!has_input || second == std::numeric_limits<int>::min()) {
      return 2;
    }

    return 0;
  }

}

int main() {
  int first = 0;
  int second = 0;

  int result = yarmolinskaya::findSecondMax(first, second);

  if (result == 1) {
    std::cerr << "Error: Invalid input sequence" << std::endl;
    return 1;
  }
  if (result == 2) {
    std::cerr << "Error: Sequence too short to calculate second maximum" << std::endl;
    return 2;
  }

  std::cout << second << std::endl;
  return 0;
}

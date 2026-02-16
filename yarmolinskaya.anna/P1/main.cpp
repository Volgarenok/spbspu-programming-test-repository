#include <iostream>
#include <limits>

namespace yarmolinskaya {
  bool readNextValue(int &value);
  void updateMaxValues(int value, int &first, int &second);
  bool validateSequence(bool has_input);
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

  bool validateSequence(bool has_input) {
    return has_input;
  }

}

namespace yarmolinskaya {
  void updateMaxValues(int value, int &first, int &second) {
    if (value > first) {
      second = first;
      first = value;
    } else if (value >= second) {
      second = value;
    }
  }

}

namespace yarmolinskaya {
  int processSequence(int &first, int &second) {
    first = std::numeric_limits<int>::min();
    second = std::numeric_limits<int>::min();

    bool has_input = false;
    int value = 0;
    int count = 0;

    while (readNextValue(value)) {
      has_input = true;
      count++;
      updateMaxValues(value, first, second);
    }

    if (!std::cin.eof() && std::cin.fail()) {
      return 1;
    }
    if (!validateSequence(has_input) || count < 2) {
      return 2;
    }
    return 0;
  }
}
namespace yarmolinskaya {
  void printError(int error_code) {
    if (error_code == 1) {
      std::cerr << "Error: Invalid input sequence" << std::endl;
    } else if (error_code == 2) {
      std::cerr << "Error: Sequence too short to calculate second maximum" << std::endl;
    }
  }

}

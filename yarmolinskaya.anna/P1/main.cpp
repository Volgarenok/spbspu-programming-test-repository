#include <iostream>
#include <limitis>

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

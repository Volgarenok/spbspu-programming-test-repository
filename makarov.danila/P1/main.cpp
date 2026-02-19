#include <iostream>
#include <limits>


int main() {
  int tnum = std::numeric_limits<int>::min();
  int mnum = std::numeric_limits<int>::min();
  int m2num = std::numeric_limits<int>::min();
  size_t count = 0;
  while (true) {
    std::cin >> tnum;
    if (std::cin.fail()) {
      std::cerr << "Invalid input" << '\n';
      return 1;
    }
    if (tnum == 0) {
      break;
    }
    count++;
    if (tnum > mnum) {
      m2num = mnum;
      mnum = tnum;
    }
  }
  if (count <= 1) {
    std::cerr << "Not enough numbers for the task" << '\n';
    return 2;
  }
  std::cout << m2num << '\n';
}

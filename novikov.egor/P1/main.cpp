#include <iostream>

int main()
{
  int num = 1;
  size_t counter = 0;
  int count_max = 0;
  int devide_max = 0;
  int late_num = 0;
  int big_num = 0;
  while (true) {
    std::cin >> num;
    if (std::cin.fail()) {
      std::cerr << "Can't read this sequence!";
      return 1;
    } else if (num == 0) {
      break;
    }
    if (counter == 0) {
      big_num = num;
      count_max = 1;
    } else {
      if (num % late_num == 0) {
        devide_max++;
      }
      if (num > big_num) {
        big_num = num;
        count_max = 1;
      } else if (num == big_num) {
        count_max++;
      }
    }
    counter++;
    late_num = num;
  }
  if (counter > 1) {
    std::cout << count_max << "\n" << devide_max - 1 << "\n";
  } else {
    std::cerr << "Sequence too short for me!";
    return 2;
  }
}

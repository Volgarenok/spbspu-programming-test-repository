#include <iostream>
#include <limits>

int main() 
{
  int tnum, mnum, m2num = std::numeric_limits<int>::min();
  size_t count = 0;
  while (true)
  {
    if (std::cin.fail()) {
      std::cerr << "Invalid input" << "\n";
      return 1;
    }
    std::cin >> tnum;
    count++;
    if (tnum == 0) {
      break;
    }
    if (tnum > mnum) {
      m2num = mnum;
      mnum = tnum;
    }
  }
  if (count <= 2) {
    std::cerr << "Not enough numbers for the task"<< "\n";
    return 2;
  }
  std::cout << m2num << "\n";

}
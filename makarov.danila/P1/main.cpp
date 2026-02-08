#include <iostream>
#include <limits>

int main() 
{
  int tnum, mnum, m2num = std::numeric_limits<int>::min();
  size_t count = 0;
  while (true)
  {
    std::cin >> tnum;
    if (tnum == 0) {
      break;
    }
    if (tnum > mnum) {
      m2num = mnum;
      mnum = tnum;
    }
  }
  std::cout << m2num << "\n";
  
}
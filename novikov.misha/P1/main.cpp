#include <iostream>
#include "inc_seq.hpp"
#include "evn_cnt.hpp"

int main()
{
  novikov::IncSeq inc;
  novikov::EvnCnt evn;

  int x = 0;
  while (std::cin >> x && x != 0) {
    inc(x);
    evn(x);
  }

  if (std::cin.fail() && !std::cin.eof()) {
    std::cerr << "Error: invalid input\n";
    return 1;
  }

  if (x != 0) {
    std::cerr << "Error: no terminating zero\n";
    return 1;
  }

  const size_t total = inc.total();

  if (total < 2) {
    std::cout << "0\n";
    if (total == 0) {
      std::cout << "0\n";
      return 0;
    }
    std::cerr << "Error: sequence too short for INC-SEQ\n";
    std::cout << evn() << '\n';
    return 2;
  }

  std::cout << inc() << '\n';
  std::cout << evn() << '\n';

  return 0;
}

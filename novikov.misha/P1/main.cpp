#include <iostream>
#include "Itrait.hpp"
#include "inc_seq.hpp"
#include "evn_cnt.hpp"

int main()
{
  using namespace novikov;

  ITrait * inc = new IncSeq();
  ITrait * evn = new EvnCnt();

  int x = 0;
  while (std::cin >> x && x != 0) {
    (*inc)(x);
    (*evn)(x);
  }

  if (std::cin.fail() && !std::cin.eof()) {
    std::cerr << "Error: invalid input\n";
    delete inc;
    delete evn;
    return 1;
  }

  if (x != 0) {
    std::cerr << "Error: no terminating zero\n";
    delete inc;
    delete evn;
    return 1;
  }

  IncSeq * inc_seq = dynamic_cast< IncSeq * >(inc);
  if (!inc_seq) {
    std::cerr << "Error: dynamic_cast failed\n";
    delete inc;
    delete evn;
    return 1;
  }

  const size_t total = inc_seq->total();

  if (total < 2) {
    std::cout << "0\n";
    if (total == 0) {
      std::cout << "0\n";
      delete inc;
      delete evn;
      return 0;
    }
    std::cerr << "Error: sequence too short for INC-SEQ\n";
    std::cout << (*evn)() << '\n';
    delete inc;
    delete evn;
    return 2;
  }

  std::cout << (*inc)() << '\n';
  std::cout << (*evn)() << '\n';

  delete inc;
  delete evn;

  return 0;
}

#include "sequence.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  nabieva::MaxCount maxCounter;
  nabieva::MaxDecreasingSequence decLength;
  int a = 0;
  while (std::cin >> a && a != 0) {
    maxCounter.upd(a);
    decLength.upd(a);
  }
  if (!std::cin.eof() && std::cin.fail()) {
    std::cerr << "Error input";
    return 1;
  }
  try {
    std::cout << maxCounter.result() << "\n";
    std::cout << decLength.result() << "\n";
  } catch (const std::logic_error& e) {
    std::cerr << e.what();
    return 2;
  }
}

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
  size_t maxCountResult = maxCounter.result();
  size_t decLengthResult = decLength.result();
  if (maxCountResult != 0) {
    std::cout << maxCountResult << "\n";
  }
  if (decLengthResult != 0) {
    std::cout << decLengthResult << "\n";
  }
  if (maxCountResult == 0 || decLengthResult == 0) {
    std::cerr << "Error too short input\n";
    return 2;
  }
  return 0;
}

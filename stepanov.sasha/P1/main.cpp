#include <iostream>
#include <stdexcept>

#include "seq.hpp"

int main()
{
  stepanov::DivPrevSeq divPrevCounter;
  stepanov::SubMaxSeq subMax;

  int val = 0;
  while (std::cin >> val && val != 0) {
    divPrevCounter.update(val);
    subMax.update(val);
  }

  if (!std::cin.eof() && std::cin.fail()) {
    std::cerr << "Input error";
    return 1;
  }

  try {
    std::cout << divPrevCounter.result() << '\n';
    std::cout << subMax.result() << '\n';
  } catch (const std::runtime_error& e) {
    std::cerr << "Not enough data\n";
    return 2;
  }

  return 0;
}

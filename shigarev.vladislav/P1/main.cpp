#include <iostream>
#include <stdexcept>

#include "DivRem.hpp"
#include "SgnChg.hpp"

int main()
{
  shigarev::SgnChg sgnChg;
  shigarev::DivRem divRem;

  for (int val = 0; std::cin >> val && val != 0;) {
    sgnChg.process(val);
    divRem.process(val);
  }
  if (std::cin.fail() && !std::cin.eof()) {
    std::cerr << "Error: invalid input\n";
    return 1;
  }

  std::cout << sgnChg.count() << "\n";

  try {
    std::cout << divRem.count() << "\n";
  } catch (const std::logic_error & Description) {
    std::cerr << "Error: " << Description.what() << "\n";
    return 2;
  }

  return 0;
}

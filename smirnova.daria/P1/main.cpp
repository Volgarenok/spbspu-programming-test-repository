#include "local_max_counter.hpp"
#include "sign_change_counter.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  smirnova::LocalMaxCounter local_max_counter;
  smirnova::SignChangeCounter sign_change_counter;
  int value;
  while (std::cin >> value && value != 0) {
    local_max_counter.addValue(value);
    sign_change_counter.addValue(value);
  }
  if (!std::cin && !std::cin.eof()) {
    std::cerr << "Error: Invalid input sequence\n";
    return 1;
  }
  try {
    std::cout << local_max_counter.getCount() << "\n";
  } catch (const std::logic_error &e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  std::cout << sign_change_counter.getCount() << "\n";
  return 0;
}

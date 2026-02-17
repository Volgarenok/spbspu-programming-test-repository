#include "local_max_counter.hpp"
#include "sign_change_counter.hpp"
#include <iostream>

int main()
{
  smirnova::LocalMaxCounter local_max_counter;
  smirnova::SignChangeCounter sign_change_counter;
  int value;
  bool has_elements = false;
  while (std::cin >> value && value != 0) {
    has_elements = true;
    local_max_counter.addValue(value);
    sign_change_counter.addValue(value);
  }
  if (!std::cin && !std::cin.eof()) {
    std::cerr << "Error: Invalid input sequence\n";
    return 1;
  }
  if (!has_elements) {
    std::cerr << "Error: Empty sequence\n";
    return 2;
  }
  std::cout << local_max_counter.getCount() << "\n";
  std::cout << sign_change_counter.getCount() << "\n";
  return 0;
}

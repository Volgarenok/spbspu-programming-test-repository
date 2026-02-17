#include "local_max_counter.hpp"
#include "sign_change_counter.hpp"
#include <iostream>
#include <string>

namespace smirnova {

int solveS7()
{
  LocalMaxCounter counter;
  int value;
  bool has_elements = false;
  while (std::cin >> value && value != 0) {
    has_elements = true;
    counter.addValue(value);
  }
  if (!std::cin && !std::cin.eof()) {
    std::cerr << "Error: Invalid input sequence\n";
    return 1;
  }
  if (!has_elements) {
    std::cerr << "Error: Empty sequence\n";
    return 2;
  }
  std::cout << counter.getCount() << "\n";
  return 0;
}

int solveS9()
{
  SignChangeCounter counter;
  int value;
  while (std::cin >> value && value != 0) {
    counter.addValue(value);
  }
  if (!std::cin && !std::cin.eof()) {
    std::cerr << "Error: Invalid input sequence\n";
    return 1;
  }
  std::cout << counter.getCount() << "\n";
  return 0;
}

} // namespace smirnova

int main(int argc, char *argv[])
{
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <s7|s9>\n";
    return 1;
  }
  const std::string mode = argv[1];
  if (mode == "s7") {
    return smirnova::solveS7();
  } else if (mode == "s9") {
    return smirnova::solveS9();
  }
  std::cerr << "Error: Unknown task '" << mode << "'\n";
  std::cerr << "Available tasks: s7, s9\n";
  return 1;
}

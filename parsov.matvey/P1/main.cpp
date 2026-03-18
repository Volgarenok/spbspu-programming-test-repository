#include <iostream>
#include <stdexcept>
#include "moninc.hpp"
#include "grtlss.hpp"

int main()
{
  int err = 0;
  int value = 0;
  parsov::IProperty * props[2] = {nullptr, nullptr};

  try {
    props[0] = new parsov::MonInc();
    props[1] = new parsov::GrtLss();
  } catch (const std::bad_alloc & e) {
    std::cerr << "Memory allocation failed\n";
    delete props[0];
    return 1;
  }

  while (std::cin >> value && value != 0) {
    for (size_t i = 0; i < 2; ++i) {
      (*props[i])(value);
    }
  }

  if (!std::cin.eof() && std::cin.fail()) {
    std::cerr << "Bad input\n";
    for (size_t i = 0; i < 2; ++i) {
      delete props[i];
    }
    return 1;
  }

  for (size_t i = 0; i < 2; ++i) {
    try {
      std::cout << (*props[i])() << "\n";
    } catch (const std::exception & e) {
      std::cerr << e.what() << "\n";
      if (err == 0) {
        err = 2;
      }
    }
  }

  for (size_t i = 0; i < 2; ++i) {
    delete props[i];
  }

  return err;
}

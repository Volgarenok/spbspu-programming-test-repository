#include <iostream>
#include <stdexcept>
#include "moninc.hpp"
#include "grtlss.hpp"

int main()
{
  int err = 0;
  int value = 0;
  parsov::MonInc mon_inc;
  parsov::GrtLss grt_lss;

  while (std::cin >> value && value != 0) {
    mon_inc(value);
    grt_lss(value);
  }

  if (!std::cin.eof() && std::cin.fail()) {
    std::cerr << "Bad input\n";
    return 1;
  }

  try {
    std::cout << mon_inc() << "\n";
  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
    if (err == 0) {
      err = 2;
    }
  }

  try {
    std::cout << grt_lss() << "\n";
  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
    if (err == 0) {
      err = 2;
    }
  }

  return err;
}

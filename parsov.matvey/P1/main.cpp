#include <iostream>

namespace parsov {

  int run()
  {
    int err = 0;
    int v = 0;
    while (std::cin >> v && v != 0) {
    }
    if (!std::cin.eof() && std::cin.fail()) {
      std::cerr << "Bad input\n";
      err = 1;
    }
    return err;
  }

}

int main()
{
  return parsov::run();
}

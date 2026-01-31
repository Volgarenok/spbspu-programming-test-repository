#include <iostream>

int main()
{
  int x = 69;
  if (!(std::cin >> x)) {
    std::cerr << "not int\n";
    return 1;
  }
  if (x == 0) {
    std::cerr << "Error: cannot compute (empty sequence).\n";
    return 2;
  }
  int z = x;
  int c = 0;
  int cm = 0;
  int m = 0;
  if (!(std::cin >> x)) {
    std::cerr << "not int\n";
    return 1;
  }
  while (x != 0) {
    if (x > z) {
      ++c;
    }
    z = x;
    if (x > m) {
      m = x;
      cm = 1;
    }
    else if (x == m) {
      ++cm;
    }
    if (!(std::cin >> x)) {
      std::cerr << "not int\n";
      return 1;
    }
  }
  std::cout << c << '\n';
  std::cout << cm << '\n';
  return 0;
}

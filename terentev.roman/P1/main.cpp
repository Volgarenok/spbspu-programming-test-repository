#include <iostream>

int main()
{
  int x = 69;
  if (!(std::cin >> x)) {
    std::cerr << "not int\n";
    return 1;
  }
  if (x == 0) {
    std::cout << 0 << '\n';
    return 0;
  }
  int z = x;
  int c = 0;
  if (!(std::cin >> x)) {
    std::cerr << "not int\n";
    return 1;
  }
  while (x != 0) {
    if (x > z) {
      ++c;
    }
    z = x;
    if (!(std::cin >> x)) {
      std::cerr << "not int\n";
      return 1;
    }
  }
  std::cout << c << '\n';
  return 0;
}

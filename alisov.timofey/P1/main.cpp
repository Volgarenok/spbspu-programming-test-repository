#include <iostream>

int main()
{
  int x;
  if (!(std::cin >> x))
  {
    std::cerr << "Not a number\n";
    return 1;
  }
  if (x == 0)
  {
    std::cerr << "Eempty sequence\n";
    return 2;
  }
  while (x != 0)
  {
    if (!(std::cin >> x))
    {
      std::cerr << "Not a number\n";
      return 1;
    }
  }
}
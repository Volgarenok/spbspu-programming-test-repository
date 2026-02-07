#include <iostream>

int main()
{
  int x = 0;
  int total = 0;

  int maxk = 0;
  int k = 0;

  int divCount = 0;
  bool divpos = true;
  int prev = 0;
  if (!(std::cin >> x))
  {
    std::cerr << "Not a number\n";
    return 1;
  }
  while (x != 0)
  {
    if (!(std::cin >> x))
    {
      std::cerr << "Not a number\n";
      return 1;
    }
    total += 1;
    if (x % 2 == 0)
    {
      k += 1;
      if (k > maxk)
      {
        maxk == k;
      }
    }
    else
    {
      k == 0;
    }
    if (total > 1)
    {
      if (prev == 0)
      {
        divpos = false;
      }
      else if (x % prev == 0)
      {
        divCount += 1;
      }
    }
    prev = x;
  }
  if (total < 2 || !divpos)
  {
    std::cerr << "Cant calculate";
    return 2;
  }
  else
  {
    std::cout << divCount << '\n';
  }
  std::cout << maxk << '\n';
}
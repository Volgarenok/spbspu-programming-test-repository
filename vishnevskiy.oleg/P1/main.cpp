#include <iostream>

bool grtLss(int first, int second, int third);

int main()
{
  int currEl = 0, secondEl = 0, firstEl = 0, grt = 0, mon = 0, currMon = 1;
  std::cin >> currEl;
  if (currEl == 0)
  {
    std::cerr << "Error : sequence is too short\n";
    return 2;
  }
  secondEl = currEl;
  std::cin >> currEl;
  if (currEl == 0)
  {
    std::cout << 1 << "\n";
    std::cerr << "Error : sequence is too short\n";
    return 2;
  }
  firstEl = secondEl;
  secondEl = currEl;
  std::cin >> currEl;
  if (currEl == 0)
  {
    if (firstEl >= secondEl)
    {
      std::cout << 2 << "\n";
    }
    else
    {
      std::cout << 1 << "\n";
    }
    std::cerr << "Error : sequence is too short\n";
    return 2;
  }
  while (currEl != 0)
  {
    firstEl = secondEl;
    secondEl = currEl;
    std::cin >> currEl;
    grt = grt+grtLss(firstEl, secondEl, currEl);
    if (secondEl >= currEl)
    {
      currMon++;
    }
    else
    {
      if (currMon > mon)
      {
        mon = currMon;
      }
      currMon = 1;
    }
    if (std::cin.fail())
    {
      std::cerr << "Input failed\n";
      return 1;
    }
  }
  if (currMon > mon)
  {
    mon = currMon;
  }
  std::cout << grt << " " << mon << "\n";
  return 0;
}


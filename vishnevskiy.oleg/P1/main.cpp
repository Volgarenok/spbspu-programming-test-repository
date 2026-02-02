#include <iostream>

bool grtLss(int first, int second, int third);

int main()
{
  int currEl = 0, secondEl = 0, firstEl = 0, grt = 0, mon = 0, currMon = 1;
  std::cin >> currEl;
  if (std::cin.fail())
  {
    std::cerr << "Input failed\n";
    return 1;
  }
  if (currEl == 0)
  {
    std::cerr << "Error : sequence is too short\n";
    return 2;
  }
  secondEl = currEl;
  std::cin >> currEl;
  if (std::cin.fail())
  {
    std::cerr << "Input failed\n";
    return 1;
  }
  if (currEl == 0)
  {
    std::cout << 1 << "\n";
    std::cerr << "Error : sequence is too short\n";
    return 2;
  }
  firstEl = secondEl;
  secondEl = currEl;
  std::cin >> currEl;
  if (std::cin.fail())
  {
    std::cerr << "Input failed\n";
    return 1;
  }
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
    if (std::cin.fail())
    {
      std::cerr << "Input failed\n";
      return 1;
    }
    grt = grt+grtLss(firstEl, secondEl, currEl);
    if (firstEl >= secondEl)
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
    firstEl = secondEl;
    secondEl = currEl;
    std::cin >> currEl;
  }
  if (firstEl >= secondEl)
  {
    currMon++;
  }
  if (currMon > mon)
  {
    mon = currMon;
  }
  std::cout << grt << " " << mon << "\n";
  return 0;
}

bool grtLss(int first, int second, int third)
{
  if (first > second && second > third)
  {
    return 1;
  }
  return 0;
}

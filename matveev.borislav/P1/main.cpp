#include <iostream>
int main()
{
  int a = 0, count_max = 0, max_num = 0, previous = 0, count_rem = 0, len=0;

  std::cin >> a;
  if (std::cin.fail())
  {
    std::cerr << "Error input" << std::endl;
    return 1;
  }
  max_num = a;
  if (a == 0)
  {
    std::cerr << "No numbers" << std::endl;
    return 2;
  }
  while (a != 0)
  {
    len++;
    if (a == max_num)
    {
      count_max++;
    }
    if (a > max_num)
    {
      max_num = a;
      count_max = 1;
    }

    if (previous != 0 && a % previous == 0)
    {
      count_rem++;
    }
    previous = a;
    std::cin >> a;
    if (std::cin.fail())
    {
      std::cerr << "Error input" << std::endl;
      return 1;
    }
  }
  if (len < 2)
  {
    std::cout << "CNT-MAX " << count_max << std::endl;
    std::cerr << "Error numbers" << std::endl;
    return 2;
  }
  std::cout << "CNT-MAX " << count_max << std::endl;
  std::cout << "DIV-REM " << count_rem << std::endl;
  return 0;
}

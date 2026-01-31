#include <iostream>
int main()
{
  int a=0, count_max=0, max_num=0, previous=0, count_rem=0;
  std::cin >> a;
  max_num=a;
  if(a == 0)
  {
    return 2;
  }
  while(a != 0)
  {
    if(a == max_num)
    {
      count_max++;
    }
    if(a > max_num)
    {
      max_num=a;
      count_max=1;
    }

    if(previous != 0 && a % previous == 0)
    {
      count_rem++;
    }
    previous=a;
    std::cin >> a;
  }
  if(count_rem == 0)
  {
    std::cout << "CNT-MAX " << count_max << std::endl;
    return 2;
  }
  std::cout << "CNT-MAX " << count_max << std::endl;
  std::cout << "DIV-REM " << count_rem << std::endl;
  return 0;
}

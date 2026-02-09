#include <iostream>

namespace lukashevich
{
  int process()
  {
    int num, prev_num, sgn_chg = 0;
    bool first_num = true;

    while (true)
    {
      if (!(std::cin >> num))
      {
        std::cerr << "error: input isnt number\n";
        return 1;
      }

      if (num == 0)
      {
        break;
      }

      if (!first_num)
      {
        if ((prev_num > 0 && num < 0) || ((prev_num < 0 && num > 0)))
        {
          ++sgn_chg;
        }
      }
      else
      {
        first_num = false;
      }

      prev_num = num;
    }

    std::cout << sgn_chg << "\n";
    return 0;
  }
}
int main()
{
  return lukashevich::process();
}

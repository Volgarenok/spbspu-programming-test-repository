#include <iostream>
#include <climits>

namespace lukashevich
{
  int process()
  {
    int num = 0, prev_num = 0, sgn_chg = 0, count = 0;
    bool first_num = true;
    int max_num = INT_MIN;
    int max_pos = -1;

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

      if (count == 0 || num > max_num)
      {
        max_num = num;
        max_pos = count;
      }

      prev_num = num;
      ++count;
    }

    bool aft_max_val = true;
    if (count == 0)
    {
      aft_max_val = false;
      std::cerr << "error: sequence = 0, aft_max cant be counted\n";
    }

    if (aft_max_val)
    {
      int aft_max = count - max_pos - 1;
      std::cout << aft_max << "\n";
    }

    std::cout << sgn_chg << "\n";

    if (!aft_max_val)
    {
      return 2;
    }
    return 0;
  }
}

int main()
{
  return lukashevich::process();
}

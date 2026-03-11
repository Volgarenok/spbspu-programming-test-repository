#include "promt.hpp"

namespace lukashevich
{
  seq_check::seq_check()
  {
    num = 0, prev_num = 0, sgn_chg = 0, count = 0;
    max_num = INT_MIN;
    max_pos = -1;
    first_num = true;
    aft_max_val = false;
    aft_max = -1;
  }

  int seq_check::proc()
  {
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
        sqn_chg(prev_num, num);
      }
      else
      {
        first_num = false;
      }

      update_max_num(num, count);

      prev_num = num;
      ++count;
    }

    if (count == 0)
    {
      aft_max_val = false;
      std::cerr << "error: sequence = 0, aft_max cant be counted\n";
    }
    else
    {
      aft_max_val = true;
      aft_max = count - max_pos - 1;
    }

    if (aft_max_val)
    {
      std::cout << get_aft_max() << "\n";
    }

    std::cout << get_sgn_chg() << "\n";

    if (!aft_max_val)
    {
      return 2;
    }
    return 0;
  }

  void seq_check::sqn_chg(int prev_num, int num)
  {
    if ((prev_num > 0 && num < 0) || (prev_num < 0 && num > 0))
    {
      ++sgn_chg;
    }
  }

  void seq_check::update_max_num(int num, int count)
  {
    if (count == 0 || num > max_num)
    {
      max_num = num;
      max_pos = count;
    }
  }

  int seq_check::get_sgn_chg()
  {
    return sgn_chg;
  }

  int seq_check::get_aft_max()
  {
    return aft_max;
  }
}


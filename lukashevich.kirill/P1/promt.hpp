#ifndef PROMT_HPP
#define PROMT_HPP

#include <iostream>
#include <climits>

namespace lukashevich
{
  struct seq_check
  {
    int num, prev_num, sgn_chg, count, aft_max;
    bool first_num, aft_max_val;
    int max_num;
    int max_pos;

    seq_check();
    int proc();
    int get_sgn_chg();
    int get_aft_max();
    void sqn_chg(int prev_num, int num);
    void update_max_num(int num, int count);
  };
}

#endif


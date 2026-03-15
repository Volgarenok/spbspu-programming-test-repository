#include "sgn_chg.hpp"

namespace lukashevich
{
  void signChangeCount::countSGN(int curr_val)
  {
    if (has_prev) {
      if ((prev_val > 0 && curr_val < 0) || (prev_val < 0 && curr_val > 0)) {
        count++;
      }
    }

    prev_val = curr_val;
    has_prev = true;
  }

  int signChangeCount::get_count() const
  {
    return count;
  }
}

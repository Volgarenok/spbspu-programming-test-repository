#include "sgn_chg.hpp"

namespace lukashevich
{
  void SignChangeCount::countSGN(int currVal)
  {
    if (hasPrev) {
      if ((prevVal > 0 && currVal < 0) || (prevVal < 0 && currVal > 0)) {
        count++;
      }
    }

    prevVal = currVal;
    hasPrev = true;
  }

  int SignChangeCount::getCount() const
  {
    return count;
  }
}

#include "sgn_chg.hpp"

lukashevich::SignChangeCount::SignChangeCount():
  count_(0),
  prevVal_(0),
  hasPrev_(false)
{}

void lukashevich::SignChangeCount::countSGN(int currVal)
{
  if (hasPrev_) {
    if ((prevVal_ > 0 && currVal < 0) || (prevVal_ < 0 && currVal > 0)) {
      count_++;
    }
  }

  prevVal_ = currVal;
  hasPrev_ = true;
}

int lukashevich::SignChangeCount::getCount() const
{
  return count_;
}

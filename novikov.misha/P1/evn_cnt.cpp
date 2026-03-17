#include "evn_cnt.hpp"
#include <cmath>

novikov::EvnCnt::EvnCnt():
  max_(0),
  cur_(0)
{}

void novikov::EvnCnt::operator()(int x)
{
  if (std::abs(x) % 2 == 0) {
    ++cur_;
    if (cur_ > max_) {
      max_ = cur_;
    }
  } else {
    cur_ = 0;
  }
}

size_t novikov::EvnCnt::operator()() const
{
  return max_;
}

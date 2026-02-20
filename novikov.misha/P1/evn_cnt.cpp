#include "evn_cnt.hpp"

namespace novikov
{

  EvnCnt::EvnCnt():
    max_(0),
    cur_(0)
  {}

  void EvnCnt::operator()(int x)
  {
    if (x % 2 == 0) {
      ++cur_;
      if (cur_ > max_) {
        max_ = cur_;
      }
    } else {
      cur_ = 0;
    }
  }

  size_t EvnCnt::operator()() const
  {
    return static_cast< size_t >(max_);
  }

}

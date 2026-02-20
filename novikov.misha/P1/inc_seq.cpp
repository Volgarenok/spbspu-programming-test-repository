#include "inc_seq.hpp"
#include <limits>

namespace novikov
{

  IncSeq::IncSeq():
    count_(0),
    total_(0),
    prev_(std::numeric_limits< int >::max())
  {}

  void IncSeq::operator()(int x)
  {
    if (x > prev_) {
      ++count_;
    }
    ++total_;
    prev_ = x;
  }

  size_t IncSeq::operator()() const
  {
    return count_;
  }

  size_t IncSeq::total() const
  {
    return total_;
  }

}

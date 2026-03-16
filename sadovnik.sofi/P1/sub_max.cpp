#include "sub_max.hpp"
#include <stdexcept>

namespace sadovnik {

SubMaxCount::SubMaxCount()
  : cnt_(0),
    max1_(std::numeric_limits<int>::min()),
    max2_(std::numeric_limits<int>::min())
{
}

void SubMaxCount::operator()(int x)
{
  if (cnt_ == 0) {
    max1_ = x;
  } else if (x > max1_) {
    max2_ = max1_;
    max1_ = x;
  } else if (x > max2_) {
    max2_ = x;
  }
  ++cnt_;
}

int SubMaxCount::operator()() const
{
  if (!valid()) {
    throw std::logic_error("Not enough numbers");
  }
  return max2_;
}

bool SubMaxCount::valid() const
{
  return cnt_ >= 2;
}

}


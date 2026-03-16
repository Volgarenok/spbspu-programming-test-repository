#include "aft_max.hpp"

namespace sadovnik {

AftMaxCount::AftMaxCount()
  : max_(std::numeric_limits<int>::min()),
    after_(0)
{
}

void AftMaxCount::operator()(int x)
{
  if (x > max_) {
    max_ = x;
    after_ = 0;
  } else {
    ++after_;
  }
}

size_t AftMaxCount::operator()() const
{
  return after_;
}

}

#include "aft_max.hpp"

sadovnik::AftMaxCount::AftMaxCount():
  max_(std::numeric_limits< int >::min()),
  after_(0)
{}

void sadovnik::AftMaxCount::operator()(int x)
{
  if (x > max_)
  {
    max_ = x;
    after_ = 0;
  }
  else
  {
    ++after_;
  }
}

size_t sadovnik::AftMaxCount::operator()() const
{
  return after_;
}

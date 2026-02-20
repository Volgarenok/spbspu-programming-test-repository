#include "seq.hpp"

#include <limits>
#include <stdexcept>

stepanov::DivPrevSeq::DivPrevSeq():
  prev_(0),
  count_(0),
  inputs_(0)
{}

void stepanov::DivPrevSeq::update(int next)
{
  ++inputs_;
  if (inputs_ > 1 && next % prev_ == 0) {
    ++count_;
  }
  prev_ = next;
}

size_t stepanov::DivPrevSeq::result() const
{
  if (inputs_ < 2) {
    throw std::runtime_error("Not enough data");
  }
  return count_;
}

stepanov::SubMaxSeq::SubMaxSeq():
  max_(std::numeric_limits<int>::min()),
  sub_max_(std::numeric_limits<int>::min()),
  inputs_(0)
{}

void stepanov::SubMaxSeq::update(int next)
{
  ++inputs_;
  if (next >= max_) {
    sub_max_ = max_;
    max_ = next;
  } else if (next >= sub_max_) {
    sub_max_ = next;
  }
}

int stepanov::SubMaxSeq::result() const
{
  if (inputs_ < 2) {
    throw std::runtime_error("Not enough data");
  }
  return sub_max_;
}

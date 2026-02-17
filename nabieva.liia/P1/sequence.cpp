#include "sequence.hpp"
#include <stdexcept>
#include <limits>

nabieva::MaxCount::MaxCount():
  maxValue_(std::numeric_limits<int>::min()),
  countMax_(0)
{}

void nabieva::MaxCount::upd(int value)
{
  if (countMax_ == 0) {
    maxValue_ = value;
    countMax_ = 1;
  }
  else if (value > maxValue_) {
    maxValue_ = value;
    countMax_ = 1;
  }
  else if (value == maxValue_) {
    ++countMax_;
  }
}

size_t nabieva::MaxCount::result() const
{
  return countMax_;
}

nabieva::MaxDecreasingSequence::MaxDecreasingSequence():
  currLength_(0),
  maxLength_(0),
  prevValue_(std::numeric_limits<int>::min())
{}

void nabieva::MaxDecreasingSequence::upd(int value)
{
  if (currLength_ == 0) {
    prevValue_ = value;
    currLength_ = 1;
  }
  else if (value <= prevValue_) {
    currLength_++;
  }
  else {
    currLength_ = 1;
  }
  prevValue_ = value;
  if (maxLength_ < currLength_) {
    maxLength_ = currLength_;
  }
}

size_t nabieva::MaxDecreasingSequence::result() const
{
  return maxLength_;
}

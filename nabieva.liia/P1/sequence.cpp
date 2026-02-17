#include "sequence.hpp"
#include <stdexcept>

namespace nabieva {
  MaxCount::MaxCount() :
    maxValue_(0),
    countMax_(0)
  {}

  void MaxCount::upd(int value)
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

  size_t MaxCount::result() const
  {
    if (countMax_ == 0) {
      throw std::logic_error("Error too short input\n");
    }
    return countMax_;
  }

  MaxDecreasingSequence::MaxDecreasingSequence() :
    currLength_(0),
    maxLength_(0),
    prevValue_(0)
  {}

  void MaxDecreasingSequence::upd(int value)
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

  size_t MaxDecreasingSequence::result() const
  {
    return maxLength_;
  }
}
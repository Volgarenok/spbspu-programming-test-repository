#include "moninc.hpp"

parsov::MonInc::MonInc():
  max_length_(0),
  current_length_(0),
  prev_val_(0),
  is_first_(true)
{}

size_t parsov::MonInc::result() const
{
  return max_length_;
}

void parsov::MonInc::update(int value)
{
  if (is_first_) {
    current_length_ = 1;
    max_length_ = 1;
    prev_val_ = value;
    is_first_ = false;
  } else {
    if (value >= prev_val_) {
      current_length_++;
    } else {
      current_length_ = 1;
    }
    if (current_length_ > max_length_) {
      max_length_ = current_length_;
    }
    prev_val_ = value;
  }
}

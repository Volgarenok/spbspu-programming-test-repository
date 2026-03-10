#include "aft_max.hpp"

khvaevskiy::aft_max::aft_max():
  count_(0),
  max_val_(0),
  max_pos_(0),
  result_(0)
{}

std::size_t khvaevskiy::aft_max::operator()() const
{
  return result_;
}

void khvaevskiy::aft_max::operator()(long long num)
{
  if (count_ == 0 || num > max_val_)
  {
    max_val_ = num;
    max_pos_ = count_;
  }
  count_++;
}

void khvaevskiy::aft_max::finalize()
{
  if (max_pos_ < count_ - 1)
    result_ = count_ - max_pos_ - 1;
  else
    result_ = 0;
}

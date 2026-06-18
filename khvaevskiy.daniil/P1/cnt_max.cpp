#include "cnt_max.hpp"

khvaevskiy::cnt_max::cnt_max():
  count_(0),
  max_val_(0),
  result_(0)
{}

std::size_t khvaevskiy::cnt_max::operator()() const
{
  return result_;
}

void khvaevskiy::cnt_max::operator()(long long num)
{
  if (count_ == 0)
  {
    max_val_ = num;
    result_ = 1;
  }
  else if (num > max_val_)
  {
    max_val_ = num;
    result_ = 1;
  }
  else if (num == max_val_)
  {
    result_++;
  }
  count_++;
}

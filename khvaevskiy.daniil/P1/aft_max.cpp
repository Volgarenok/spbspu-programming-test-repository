#include "aft_max.hpp"

khvaevskiy::aft_max::aft_max():
  count_(0),
  max_val_(0),
  max_pos_(0),
  result_(0),
  max_found_(false)
{}

std::size_t khvaevskiy::aft_max::operator()() const
{
  return result_;
}

void khvaevskiy::aft_max::operator()(long long num)
{
  if (!max_found_)
  {
    if (count_ == 0 || num > max_val_)
    {
      max_val_ = num;
      max_pos_ = count_;
      max_found_ = true;
    }
  }
  else
  {
    if (num > max_val_)
    {
      max_val_ = num;
      max_pos_ = count_;
      result_ = 0;
    }
    else if (num < max_val_)
    {
      result_++;
    }
  }
  count_++;
}

void khvaevskiy::aft_max::finalize()
{}

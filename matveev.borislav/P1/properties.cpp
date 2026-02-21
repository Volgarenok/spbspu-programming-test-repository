#include "properties.hpp"

#include <stdexcept>
#include <limits>

void matveev::ISeqProperty::operator()(int value)
{
  next(value);
}

size_t matveev::ISeqProperty::operator()() const
{
  return result();
}

matveev::CntMaxProperty::CntMaxProperty():
 max(std::numeric_limits <int>::min()),
 count(0)
{
}

void matveev::CntMaxProperty::next(int value)
{
  if (value > max)
  {
    max = value;
    count = 1;
  }
  else if (value == max)
  {
    ++count;
  }
}

size_t matveev::CntMaxProperty::result() const
{
  return count;
}

matveev::DivRemProperty::DivRemProperty(): previous(0), count(0), total(0)
{
}

void matveev::DivRemProperty::next(int value)
{
  if (total > 0 && previous != 0 && value % previous == 0)
  {
    ++count;
  }

  previous = value;
  ++total;
}

size_t matveev::DivRemProperty::result() const
{
  if (total < 2)
  {
    throw std::logic_error("Error numbers");
  }
  return count;
}

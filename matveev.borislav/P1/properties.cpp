#include "properties.hpp"

#include <stdexcept>
#include <limits>

namespace matveev
{
  void ISeqProperty::operator()(int value)
  {
    next(value);
  }

  size_t ISeqProperty::operator()() const
  {
    return result();
  }
  CntMaxProperty::CntMaxProperty(): max(std::numeric_limits<int>::min()),count(0)
  {
  }

  void CntMaxProperty::next(int value)
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

  size_t CntMaxProperty::result() const
  {
    return count;
  }
  DivRemProperty::DivRemProperty(): previous(0), count(0), total(0)
  {
  }

  void DivRemProperty::next(int value)
  {
    if (total > 0 && previous != 0 && value % previous == 0)
    {
      ++count;
    }

    previous = value;
    ++total;
  }

  size_t DivRemProperty::result() const
  {
    if (total < 2)
    {
      throw std::logic_error("Error numbers");
    }
    return count;
  }
  void properties(ISeqProperty* props[property], CntMaxProperty& max, DivRemProperty& div)
  {
    props[0] = &max;
    props[1] = &div;
  }
}

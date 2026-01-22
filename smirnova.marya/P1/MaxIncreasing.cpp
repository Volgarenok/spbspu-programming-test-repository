#include "MaxIncreasing.hpp"

MaxIncreasing::MaxIncreasing() : last(0), current(0), maximum(0), hasValue(false) {}

bool MaxIncreasing::do_add(int value) {
  if (!hasValue) {
      last = value;
      current = maximum = 1;
      hasValue = true;
      return false;
  }
  if (value > last)
      current++;
  else
      current = 1;
  if (current > maximum)
      maximum = current;
  last = value;
  return true;
}

int MaxIncreasing::value() const
{
  return maximum;
}

bool MaxIncreasing::computable() const
{
  return hasValue;
}

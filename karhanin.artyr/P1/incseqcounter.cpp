#include "incseqcounter.hpp"

karhanin::IncSeqCounter::IncSeqCounter()
{
  name = "The maximum number of numbers greater than the previous one: ";
}
void karhanin::IncSeqCounter::operator()(int value)
{
  int temp = curValue;
  curValue = value;
  if (temp < curValue && temp && value)
  {
  count++;
  }
}
int karhanin::IncSeqCounter::operator()() const
{
  return count;
}

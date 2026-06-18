#include "evenseqcounter.hpp"

karhanin::EvenSeqCounter::EvenSeqCounter() :curCount(0)
{
  name = "Maximum number of consecutive even numbers: ";
  count = 0;
}
int karhanin::EvenSeqCounter::operator()() const
{
  return count;
}
void karhanin::EvenSeqCounter::operator()(int value)
{
  if (value == 0)
  {
    count = curCount;
    return;
  }
  if (value % 2 == 0)
  {
    curCount++;
    return;
  }
  if (curCount > count)
  {
    count = curCount;
  }
  curCount = 0;
}

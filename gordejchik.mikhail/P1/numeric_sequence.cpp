#include "numeric_sequence.hpp"
#include <limits>
#include <stdexcept>

size_t gordejchik::SeqProperty::operator()() const
{
  return result();
}

void gordejchik::SeqProperty::operator()(int number)
{
  next(number);
}

gordejchik::EvenCount::EvenCount():
  maxEvenCount_(0),
  currentEvenCount_(0)
{}

size_t gordejchik::EvenCount::result() const
{
  return maxEvenCount_;
}

void gordejchik::EvenCount::next(int number)
{
  if (number % 2 == 0)
  {
    ++currentEvenCount_;
    if (currentEvenCount_ > maxEvenCount_)
    {
      maxEvenCount_ = currentEvenCount_;
    }
  }
  else
  {
    currentEvenCount_ = 0;
  }
}

gordejchik::LocalMax::LocalMax():
  localMaxCount_(0),
  previousNumber_(std::numeric_limits< int >::max()),
  currentNumber_(std::numeric_limits< int >::max()),
  totalNumbers_(0)
{}

size_t gordejchik::LocalMax::result() const
{
  if (totalNumbers_ == 0)
  {
    throw std::logic_error("Error: sequence too short for LOC-MAX");
  }
  return localMaxCount_;
}

void gordejchik::LocalMax::next(int number)
{
  if (currentNumber_ > previousNumber_ && currentNumber_ > number)
  {
    ++localMaxCount_;
  }
  previousNumber_ = currentNumber_;
  currentNumber_ = number;
  ++totalNumbers_;
}

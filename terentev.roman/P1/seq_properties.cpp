#include "seq_properties.hpp"

#include <stdexcept>

std::size_t terentev::CountGreaterThanPrev::result() const
{
  return c;
}

void terentev::CountGreaterThanPrev::next(int x)
{
  if (prev == 0) {
    prev = x;
    return;
  }
  if (x > prev) {
    ++c;
  }
  prev = x;
}

std::size_t terentev::CountMaxOccurrences::result() const
{
  return cnt;
}

void terentev::CountMaxOccurrences::next(int x)
{
  if (cnt == 0) {
    max = x;
    cnt = 1;
    return;
  }
  if (x > max) {
    max = x;
    cnt = 1;
  } else if (x == max) {
    ++cnt;
  }
}

terentev::ISeqProperty* terentev::get_prop(const std::string& name)
{
  if (name == "gt-prev") {
    return new CountGreaterThanPrev();
  } else if (name == "max-cnt") {
    return new CountMaxOccurrences();
  }
  throw std::invalid_argument("unknown property: " + name);
}

#include "iproperty.hpp"

size_t parsov::IProperty::operator()() const
{
  return result();
}

void parsov::IProperty::operator()(int value)
{
  update(value);
}

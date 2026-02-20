#include "property.hpp"

size_t lachugin::SeqProperty::operator()() const
{
  return res();
}

void lachugin::SeqProperty::operator()(int value)
{
  next(value);
}

void lachugin::deletePropertys(SeqProperty* propertys[], size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    delete propertys[i];
  }
}

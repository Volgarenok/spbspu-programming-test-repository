#ifndef LACHUGIN_PROPERTY_HPP
#define LACHUGIN_PROPERTY_HPP

#include <cstddef>

namespace lachugin
{
  struct SeqProperty
  {
    virtual ~SeqProperty() = default;

    size_t operator()() const;
    void operator()(int value);

  private:
    virtual void next(int value) = 0;
    virtual size_t res() const = 0;
  };
  void deletePropertys(SeqProperty* propertys[], size_t size);
}

#endif

#ifndef LACHUGIN_SEQ_PROPERTY_HPP
#define LACHUGIN_SEQ_PROPERTY_HPP
#include <cstddef>

namespace lachugin
{
  struct SeqProperty
  {
    size_t operator()() const
    {
      return res();
    }

    void operator()(int value)
    {
      next(value);
    }

    virtual ~SeqProperty() = default;

  private:
    virtual void next(int value) = 0;
    virtual size_t res() const = 0;
  };
}

#endif

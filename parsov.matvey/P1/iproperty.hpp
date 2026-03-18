#ifndef IPROPERTY_HPP
#define IPROPERTY_HPP

#include <cstddef>

namespace parsov {

  class IProperty {
  public:
    virtual ~IProperty() = default;
    size_t operator()() const;
    void operator()(int value);
  private:
    virtual size_t result() const = 0;
    virtual void update(int value) = 0;
  };

}

#endif

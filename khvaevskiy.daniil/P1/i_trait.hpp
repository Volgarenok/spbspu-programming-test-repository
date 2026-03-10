#ifndef I_TRAIT_HPP
#define I_TRAIT_HPP

#include <cstddef>

namespace khvaevskiy
{
  class i_trait
  {
  public:
    virtual ~i_trait() = default;
    virtual std::size_t operator()() const = 0;
    virtual void operator()(long long) = 0;
  };
}

#endif

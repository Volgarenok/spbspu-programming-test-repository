#include "virtual.hpp"

namespace traits
{
  void ITrait::operator()(int a)
  {
    process(a);
  }
  size_t ITrait::operator()() const
  {
    return result();
  }
}

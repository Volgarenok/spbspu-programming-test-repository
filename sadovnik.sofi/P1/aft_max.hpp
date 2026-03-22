#ifndef AFT_MAX_HPP
#define AFT_MAX_HPP

#include <cstddef>
#include <limits>

namespace sadovnik
{
  class AftMaxCount
  {
  public:
    AftMaxCount();
    void operator()(int x);
    size_t operator()() const;

  private:
    int max_;
    size_t after_;
  };
}

#endif

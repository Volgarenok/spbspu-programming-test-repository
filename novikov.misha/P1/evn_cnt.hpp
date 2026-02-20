#ifndef EVN_CNT_HPP
#define EVN_CNT_HPP

#include <cstddef>

namespace novikov
{

  class EvnCnt
  {
  public:
    EvnCnt();
    void operator()(int x);
    size_t operator()() const;

  private:
    int max_;
    int cur_;
  };

}

#endif

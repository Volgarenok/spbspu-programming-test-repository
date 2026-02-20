#ifndef EVN_CNT_HPP
#define EVN_CNT_HPP

#include "Itrait.hpp"

namespace novikov
{

  class EvnCnt: public ITrait
  {
  public:
    EvnCnt();
    virtual ~EvnCnt() = default;
    virtual void operator()(int x);
    virtual size_t operator()() const;

  private:
    int max_;
    int cur_;
  };

}

#endif

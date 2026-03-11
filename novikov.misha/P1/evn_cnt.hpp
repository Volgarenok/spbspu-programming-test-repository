#ifndef EVN_CNT_HPP
#define EVN_CNT_HPP

#include "Itrait.hpp"

namespace novikov
{

  class EvnCnt: public ITrait
  {
  public:
    EvnCnt();
    virtual ~EvnCnt() override = default;
    virtual void operator()(int x) override;
    virtual size_t operator()() const override;

  private:
    size_t max_;
    size_t cur_;
  };

}

#endif

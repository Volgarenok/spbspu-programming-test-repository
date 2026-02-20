#ifndef INC_SEQ_HPP
#define INC_SEQ_HPP

#include "Itrait.hpp"

namespace novikov
{

  class IncSeq: public ITrait
  {
  public:
    IncSeq();
    virtual ~IncSeq() = default;
    virtual void operator()(int x);
    virtual size_t operator()() const;
    size_t total() const;

  private:
    size_t count_;
    size_t total_;
    int prev_;
  };

}

#endif

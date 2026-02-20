#ifndef INC_SEQ_HPP
#define INC_SEQ_HPP

#include <cstddef>

namespace novikov
{

  class IncSeq
  {
  public:
    IncSeq();
    void operator()(int x);
    size_t operator()() const;
    size_t total() const;

  private:
    size_t count_;
    size_t total_;
    int prev_;
  };

}

#endif

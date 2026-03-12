#ifndef SUB_MAX_hpp
#define SUB_MAX_hpp

#include <cstddef>

namespace sadovnik
{

  class SubMaxCount
  {
  public:
    SubMaxCount();
    void operator()(int x);
    size_t operator()() const;
    bool valid() const;

    private:
    size_t cnt;
    int max1;
    int max2;
    bool has_max2;
  };

}

#endif

#ifndef SUB_MAX_hpp
#define SUB_MAX_hpp

#include <cstddef>
#include <limits>

namespace sadovnik {

class SubMaxCount {
public:
  SubMaxCount();
  void operator()(int x);
  int operator()() const;

private:
  bool valid() const;
  size_t cnt_;
  int max1_;
  int max2_;
};

}

#endif


#ifndef AFT_MAX_hpp
#define AFT_MAX_hpp

#include <cstddef>
#include <limits>

namespace sadovnik {

class AftMaxCount {
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


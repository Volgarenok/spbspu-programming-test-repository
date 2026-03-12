#ifndef AFT_MAX
#define AFT_MAX

#include <cstddef>

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
  bool found_;
  size_t after_;
};

}

#endif

#ifndef SUB_MAX
#define SUB_MAX

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
  size_t cnt_;
  int max1_;
  int max2_;
  bool has_max2_;
};

}

#endif

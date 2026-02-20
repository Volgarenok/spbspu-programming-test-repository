#ifndef INCSEQ_HPP
#define INCSEQ_HPP

#include <cstddef>

namespace shevchenko
{
struct IncSeq
{
  IncSeq();
  void operator()(int a);
  size_t operator()() const;

private:
  size_t count_;
  int prev_;
  bool first_;
};

}

#endif

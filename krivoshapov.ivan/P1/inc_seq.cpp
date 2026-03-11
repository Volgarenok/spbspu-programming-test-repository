#include "inc_seq.hpp"

void krivoshapov::IncSeq::upd(int a)
{
  if (n_ > 0 && a > prev_)
  {
    ++count_;
  }
  prev_ = a;
  ++n_;
}

size_t krivoshapov::IncSeq::result() const
{
  return count_;
}

const char *krivoshapov::IncSeq::name() const
{
  return "inc-seq";
}

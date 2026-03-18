#include "SgnChg.hpp"

namespace shigarev {

  int sign(int val)
  {
    return (val > 0) - (val < 0);
  }

}

void shigarev::SgnChg::process(int val)
{
  const int cur = sign(val);
  if (prevSign_ != 0 && cur != 0 && cur != prevSign_) {
    count_++;
  }
  if (cur != 0) {
    prevSign_ = cur;
  }
}

std::size_t shigarev::SgnChg::count() const
{
  return count_;
}

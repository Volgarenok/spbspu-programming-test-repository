#include "props.hpp"

namespace lachugin
{
  void props(SeqProperty* p[property], AftMax& max, CntMin& min)
  {
    p[0] = &max;
    p[1] = &min;
  }
}

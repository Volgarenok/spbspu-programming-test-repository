#ifndef AFT_MAX_HPP
#define AFT_MAX_HPP

#include <climits>
namespace lukashevich
{
  class AfterMaxCount
  {
    private:
      int maxVal;
      int maxPos;
      int currPos;

    public:
      AfterMaxCount():
        maxVal(INT_MIN),
        maxPos(-1),
        currPos(0)
      {}

      void processNext(int value);
      int getCountAftMax() const;
      bool hasMax() const;
  };
}

#endif

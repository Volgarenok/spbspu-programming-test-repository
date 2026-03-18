#ifndef AFT_MAX_HPP
#define AFT_MAX_HPP

#include <climits>
namespace lukashevich
{
  class AfterMaxCount
  {
    public:
      AfterMaxCount();

      void processNext(int value);
      int getCountAftMax() const;
      bool hasMax() const;

    private:
      int maxVal_;
      int maxPos_;
      int currPos_;
  };
}

#endif

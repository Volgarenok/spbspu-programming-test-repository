#include <iostream>

namespace lachugin
{
  struct isZero
  {
    bool checked = false;

    bool check(int x)
    {
      if (!checked)
      {
        return false;
      }
      return x == 0;
    }
  };

  void aftMax(int n, int& k, int& res)
  {
    if (n < k)
    {
      ++res;
    }
    else
    {
      k = n;
      res = 0;
    }
  }

  void cntMin(int n, int& k, int& res)
  {
    if (n == k)
    {
      ++res;
    }
    else if (n < k)
    {
      res = 0;
      k = n;
    }
  }

}

int main()
{
  lachugin::isZero z;
  int n = 0;

  int hlpRes1 = 0;
  int hlpRes2 = 0;

  int res1 = 0;
  int res2 = 0;

  while (!z.check(n)) {
    if (!z.checked)
    {
      z.checked = true;
      std::cin >> n;
      hlpRes1 = n;
      hlpRes2 = n;
      continue;
    }
    lachugin::aftMax(n, hlpRes1, res1);
    lachugin::cntMin(n, hlpRes2, res2);
    std::cin >> n;
  }

}

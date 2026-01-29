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
        checked = true;
        return false;
      }
      return x == 0;
    }
  };

  void aftMax(int& n, int& k, int& res)
  {
    k = n;
    if (n < k && k != 0)
    {
      ++res;
      n = k;
    }
    else
    {
      res = 0;
    }
  }

}

int main()
{
  lachugin::isZero z;
  int n = 0;

  int hlpRes1 = 0;

  int res1 = 0;
  int res2 = 0;

  while (!z.check(n)) {
    lachugin::aftMax(n, hlpRes1, res1);

    std::cin >> n;
  }

}

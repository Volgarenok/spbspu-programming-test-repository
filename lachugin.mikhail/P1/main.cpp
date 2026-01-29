#include <iostream>

namespace lachugin
{
  bool isZero(int n)
  {
    if (n == 0)
    {
      return true;
    }
    return false;
  }

  void aftMax(std::istream& in, int& n, int& res)
  {
    int k = n;
    in >> n;
    if (n < k)
    {
      ++res;
      n = k;
    }
  }

}

int main()
{
  int n = 0;

  int res1;
  int res2;

}

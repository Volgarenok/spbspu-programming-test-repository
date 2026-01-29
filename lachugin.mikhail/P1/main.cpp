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
  int n = 1;

  int res1 = 0;
  int res2 = 0;


}

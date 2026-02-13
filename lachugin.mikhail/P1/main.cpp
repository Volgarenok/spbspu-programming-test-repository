#include <iostream>

namespace lachugin
{
  struct Base {
    size_t operator()() const
    {
      return res();
    }
    void operator()(int value)
    {
      next(value);
    }
    virtual ~Base() = default;

  private:
    virtual void next(int value) = 0;
    virtual size_t res() const = 0;
  };

  class Count : Base {
    size_t count = 0;
    void next(int) override {
      count++;
    }
    size_t res() const override {
      return count;
    }
  };

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

  int k = 0;
  bool inputErr = false;
  bool calcErr = false;

  while (!z.check(n))
  {
    if (!z.checked)
    {
      z.checked = true;
      std::cin >> n;
      if (std::cin.fail())
      {
        inputErr = true;
        break;
      }
      hlpRes1 = n;
      hlpRes2 = n;
      ++k;
      continue;
    }


    lachugin::aftMax(n, hlpRes1, res1);
    lachugin::cntMin(n, hlpRes2, res2);
    std::cin >> n;
    ++k;
  }

  if (inputErr)
  {
    std::cerr << "Error: invalid input sequence\n";
    return 1;
  }

  if (k < 2)
  {
    std::cout << "Error: insufficient sequence length\n";
    calcErr = true;
  }

  std::cout << res1 << "\n" << res2;

  if (calcErr)
  {
    return 2;
  }
}

#include <iostream>

namespace lachugin
{
  struct Base
  {
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

  class Count: public Base
  {
    size_t count = 0;
    void next(int) override
    {
      count++;
    }
    size_t res() const override
    {
      return count;
    }
  };

  class AftMax: public Base
  {
    void next(int value) override
    {
      if (isFrst)
      {
        isFrst = false;
        max = value;
        return;
      }
      if (value < max)
      {
        count++;
      }
      else
      {
        max = value;
        count = 0;
      }
    }
    size_t res() const override
    {
      return count;
    }
    size_t count = 0;
    int max = 0;
    bool isFrst = true;
  };

  class CntMin: public Base
  {
    void next(int value) override
    {
      if (isFrst)
      {
        isFrst = false;
        min = value;
        count++;
        return;
      }
      if (value == min)
      {
        count++;
      }
      else if (value < min)
      {
        min = value;
        count = 1;
      }
    }
    size_t res() const override
    {
      return count;
    }
    size_t count = 0;
    int min = 0;
    bool isFrst = true;
  };

}

int main()
{
  lachugin::Count k;
  lachugin::AftMax max;
  lachugin::CntMin min;

  bool inputErr = false;
  bool calcErr = false;

  int n = 0;
  std::cin >> n;
  if (std::cin.fail())
  {
    inputErr = true;
  }
  while (n != 0)
  {
    max(n);
    min(n);
    k(n);
    std::cin >> n;
    if (std::cin.fail())
    {
      inputErr = true;
    }
  }

  if (inputErr)
  {
    std::cerr << "Error: invalid input sequence\n";
    return 1;
  }

  if (k() < 2)
  {
    std::cout << "Error: insufficient sequence length\n";
    calcErr = true;
  }

  std::cout << max() << "\n" << min();

  if (calcErr)
  {
    return 2;
  }
}

#include <iostream>

namespace lachugin
{
  struct SeqProperty
  {
    size_t operator()() const
    {
      return res();
    }
    void operator()(int value)
    {
      next(value);
    }
    virtual ~SeqProperty() = default;

  private:
    virtual void next(int value) = 0;
    virtual size_t res() const = 0;
  };

  class Count: public SeqProperty
  {
    size_t count = 0;
    void next(int) override
    {
      count++;
    }
    size_t res() const override
    {
      if (count < 2)
      {
        throw std::logic_error("insufficient sequence length");
      }
      return count;
    }
  };

  class AftMax: public SeqProperty
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

  class CntMin: public SeqProperty
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
  lachugin::SeqProperty* props[] = {&max, &min, &k};

  int n = 0;

  while (std::cin >> n && n != 0)
  {
    for (auto* p: props)
    {
      (*p)(n);
    }
  }

  if (std::cin.fail())
  {
    std::cerr << "Error: invalid input sequence\n";
    return 1;
  }

  try
  {
    k();
    std::cout << max() << "\n" << min();
  }
  catch (const std::logic_error&)
  {
    std::cout << "Error: insufficient sequence length\n";
    return 2;
  }

}

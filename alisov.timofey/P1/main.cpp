#include <iostream>
namespace alisov
{
  struct ITrait
  {
    virtual void operator()(int a) = 0;
    virtual int operator()() const = 0;
    virtual ~ITrait() = default;
  };

  struct DivRem: ITrait
  {
    DivRem():
      count_(0),
      total_(0),
      prev_(0)
    {}

    void operator()(int a) override
    {
      total_++;

      if (prev_ != 0 && a % prev_ == 0)
      {
        count_++;
      }

      prev_ = a;
    }

    int operator()() const override
    {
      if (total_ < 2)
      {
        throw std::exception();
      }
      return count_;
    }

  private:
    size_t count_;
    int total_;
    int prev_;
  };

  struct EvenCount: ITrait
  {
    EvenCount():
      current_(0),
      max_(0)
    {}

    void operator()(int a) override
    {
      if (a % 2 == 0)
      {
        current_++;
        if (current_ > max_)
        {
          max_ = current_;
        }
      }
      else
      {
        current_ = 0;
      }
    }

    int operator()() const override
    {
      return max_;
    }

  private:
    int current_;
    int max_;
  };
}
int main()
{
  alisov::DivRem divrem;
  alisov::EvenCount evencnt;

  int number;
  while ((std::cin >> number) && (number != 0))
  {
    divrem(number);
    evencnt(number);
  }

  if (std::cin.fail())
  {
    std::cerr << "Input Error\n";
    return 1;
  }
  try
  {
    std::cout << divrem() << '\n';
  }
  catch (const std::exception &e)
  {
    std::cerr << "Cant calculate\n";
    std::cout << 0 << '\n';
    std::cout << evencnt() << '\n';

    return 2;
  }
  std::cout << evencnt() << '\n';
}

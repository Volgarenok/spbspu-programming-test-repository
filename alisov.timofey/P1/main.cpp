#include <iostream>

struct ITrait
{
  virtual void operator()(int a) = 0;
  virtual int operator()() = 0;
  virtual ~ITrait() = default;
};

struct DivRem: ITrait
{
  DivRem():
    count_(0),
    total_(0),
    prev_(0)
  {}

  void operator()(int a)
  {
    total_++;

    if (prev_ != 0 && a % prev_ == 0)
    {
      count_++;
    }

    prev_ = a;
  }

  int operator()()
  {
    return count_;
  }

private:
  int count_;
  int total_;
  int prev_;
};

struct EvenCount: ITrait
{
  EvenCount():
    current_(0),
    max_(0)
  {}

  void operator()(int a)
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

  int operator()()
  {
    return max_;
  }

private:
  int current_;
  int max_;
};

int main()
{
  int number = 0;

  DivRem divrem;
  EvenCount evencnt;
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

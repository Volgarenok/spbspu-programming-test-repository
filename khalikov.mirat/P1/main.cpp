#include <iostream>

struct ITrait
{
  virtual void operator()(int a) = 0;
  virtual int operator()() = 0;
  virtual ~ITrait() = default;
};

struct LocMin : ITrait
{
  LocMin()
  {
    k_ = 0;
    min_ = 0;
    temp_ = 0;
    firstadd_ = true;
  }

  void operator()(int a)
  {
    if (firstadd_)
    {
      min_ = a;
      k_++;
      firstadd_ = false;
    }
    else
    {
      temp_ = a;
      k_++;
      if (min_ > temp_)
      {
        min_ = temp_;
      }
    }
  }

  int operator()()
  {
    return min_;
  }

  private:
    bool firstadd_;
    size_t k_;
    int min_;
    int temp_;
};

int main()
{
  int number = 0;
  LocMin a;
  while(std::cin >> number)
  {
    a(number);
  }
  std::cout << a() << "\n";
}

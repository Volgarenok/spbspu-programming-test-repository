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

struct GrtLss : ITrait
{
  GrtLss()
  {
    k_ = 0;
    prev_ = 0;
    next_ = 0;
    act_ = 0;
    firstadd_ = true;
  }

  void operator()(int a)
  {
    if (firstadd_)
    {
      prev_ = a;
      act_ = a;
      next_ = a;
      firstadd_ = false;
    }
    else
    {
      prev_ = act_;
      act_ = next_;
      next_ = a;
      if ((act_ > next_) && (act_ < prev_))
      {
        k_++;
      }
    }
  }

  int operator()()
  {
    return k_;
  }

  private:
    bool firstadd_;
    int k_;
    int prev_;
    int act_;
    int next_;
};


int main()
{
  int number = 0;
  LocMin a;
  GrtLss b;
  while(std::cin >> number)
  {
    a(number);
    b(number);
  }
  std::cout << a() << "\n";
  std::cout << b() << "\n";
}

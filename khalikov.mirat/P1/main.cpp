#include <iostream>

struct ITrait
{
  virtual void operator()(int a) = 0;
  virtual int operator()() = 0;
  virtual ~ITrait() = default;
};

struct Size : ITrait
{
  Size()
  {
    k_ = 0;
  }
  void operator()(int a)
  {
    k_++;
  }
  int operator()()
  {
    return k_;
  }
  private:
    int k_;
};

struct LocMin : ITrait
{
  LocMin()
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
      if ((act_ < next_) && (act_ < prev_))
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
  Size c;
  while(std::cin >> number)
  {
    a(number);
    b(number);
    c(number);
  }
  if (!(std::cin.eof()))
  {
    std::cerr << "Seq is not read. Input Error" << "\n";
    return 1;
  }
  if (c() < 3)
  {
    std::cerr << "Seq is not read. Not enough numbers!" << "\n";
    return 2;
  }
  std::cout << "LOCMIN = " << a() << "\n";
  std::cout << "GRTLSS = " << b() << "\n";
  std::cout << "SIZE = " << c() << "\n";
}

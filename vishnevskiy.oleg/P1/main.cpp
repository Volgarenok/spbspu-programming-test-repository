#include <iostream>

struct grtLss {
  grtLss() : count_(0), first_(0), second_(0), third_(0), f_(0) {}
  void operator()(int a)
  {
    first_ = second_;
    second_ = third_;
    third_ = a;
    if (f < 2)
    {
      f++;
    }
    else
    {
      if (first_ > second_ && second_ > third_)
      {
        count_++;
      }
    }
  }
  size_t operator()() const
  {
    return count_;
  }
 private:
  size_t count_;
  int first_, second_, third_, f_;
};

struct monDec {
  monDec() : tempCount_(0), count_(0), curr_(0), prev_(0), f_(0) {}
  void operator()(int a)
  {
    prev_ = curr_;
    curr_ = a;
    if (f == 0)
    {
      tempCount_ = 1;
      f = 1;
    }
    else
    {
      if (tempCount_ > count_)
      {
        count_ = tempCount_;
      }
      tempCount_ = 0;
    }
  }
  size_t operator()() const
  {
    return count_;
  }
 private:
  size_t count_, tempCount_;
  int curr_, prev_, f_;
};

int main()
{
  int el = 0;
  grtLss g;
  monDec m;
  while (std::cin >> el)
  {
    g(el);
    m(el);
  }
  if (!std::cin.eof())
  {
    std::cerr << "Input failed\n";
    return 1;
  }
  std::cout << g() << " " << m() << "\n";
  return 0;
}



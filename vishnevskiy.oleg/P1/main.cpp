#include <iostream>

struct grtLss {
  grtLss() : count_(0), first_(0), second_(0), third_(0), f_(0) {}
  void operator()(int a)
  {
    first_ = second_;
    second_ = third_;
    third_ = a;
    if (f_ < 2)
    {
      f_++;
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
  bool operator()(size_t &error)
  {
    if (f_ < 2)
    {
      if (error == 0) {
        error = 2;
      }
      std::cerr << "Error : sequence is too short\n";
      return true;
    }
    else
    {
      error = 0;
      return false;
    }
    return false;
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
    if (f_ == 0)
    {
      tempCount_ = 1;
      f_ = 1;
    }
    else
    {
      f_ = 2;
      if (prev_ >= curr_)
      {
        tempCount_++;
      }
      else
      {
        tempCount_ = 1;
      }
      if (tempCount_ > count_)
      {
        count_ = tempCount_;
      }
    }
  }
  size_t operator()() const
  {
    return count_;
  }
  bool operator()(size_t &error)
  {
    if (f_ != 2)
    {
      if (error == 0){
        error = 2;
      }
      std::cerr << "Error : sequence is too short\n";
      return true;
    }
    else
    {
      error = 0;
      return false;
    }
    return false;
  }
 private:
  size_t tempCount_, count_;
  int curr_, prev_, f_;
};

int main()
{
  int el = 0;
  size_t error = 0;
  grtLss g;
  monDec m;
  while (std::cin >> el && el != 0)
  {
    g(el);
    m(el);
  }
  if (std::cin.fail())
  {
    std::cerr << "Input failed\n";
    return 1;
  }
  if (!g(error))
  {
    std::cout << g() << " ";
  }
  if (!m(error))
  {
    std::cout << m() << "a";
  }
  std::cout << "\n";
  return error;
}

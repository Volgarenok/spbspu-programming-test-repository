#include <iostream>

namespace khalikov
{
  struct ITrait
  {
    virtual void operator()(int a) = 0;
    virtual int operator()() = 0;
    virtual ~ITrait() = default;
  };

  struct Size: ITrait
  {
    Size()
    {
      k_ = 0;
    }
    void operator()(int)
    {
      k_++;
    }
    int operator()()
    {
      if (k_ < 3)
      {
        throw std::runtime_error("Not enough numbers!");
      }
      else
      {
        return k_;
      }
    }
    private:
      int k_;
  };

  struct LocMin: ITrait
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

  struct GrtLss: ITrait
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
}

int main()
{
  namespace khal = khalikov;
  int number = 0;
  int size = 0;
  khal::LocMin a;
  khal::GrtLss b;
  khal::Size c;
  try
  {
    while((std::cin >> number) && (number != 0))
    {
      a(number);
      b(number);
      c(number);
    }
    if (std::cin.fail())
    {
      std::cerr << "Seq is not read. Input Error" << "\n";
      return 1;
    }
    size = c();
  }
  catch (...)
  {
    std::cerr << "Seq is not read. Not enough numbers!" << "\n";
    return 2;
  }
    std::cout << "SIZE = " << size << "\n";
    std::cout << "LOCMIN = " << a() << "\n";
    std::cout << "GRTLSS = " << b() << "\n";
}

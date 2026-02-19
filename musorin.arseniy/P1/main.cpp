#include <iostream>
namespace musorin {
  struct CountMax
  {
  public:
    void setMax(int a)
    {
      max_ = a;
    }
    void update(int a)
    {
      if (a > max_)
      {
        max_ = a;
        count_ = 1;
      }
      else if (a == max_)
      {
        ++count_;
      }
    }
    size_t getResult() const
    {
      return count_;
    }
  private:
    int max_ = 0;
    size_t count_ = 1;
  };
  struct SubMax
  {
  public:
    void setMax(int a)
    {
      max_ = a;
    }
    void update(int a)
    {
      if (a >= max_)
      {
        secondMax_ = max_;
        max_ = a;
      }
    }
    int getResult() const
    {
      return secondMax_;
    }
  private:
    int max_ = 0;
    int secondMax_ = 0;
  };
}
int main()
{
  using namespace musorin;
  int a = 0;
  CountMax w;
  SubMax e;
  std::cin >> a;
  if (a == 0)
  {
    std::cerr << "Error: sequence is too small\n";
    return 2;
  }
  w.setMax(a);
  e.setMax(a);
  while (std::cin >> a)
  {
    if (a == 0)
    {
      break;
    }
    w.update(a);
    e.update(a);
  }
  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Error: invalid input\n";
    return 1;
  }
  if (e.getResult() == 0)
  {
    std::cerr << "Error: sequence is too small(sub_max)\n";
    std::cout << "number of local max: " << w.getResult() << "\n";
    return 2;
  }
  std::cout << "number of local max: " << w.getResult() << "\n";
  std::cout << "second max (max if you remove max): "
      << e.getResult() << "\n";
  return 0;
}

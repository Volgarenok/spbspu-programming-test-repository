#include <iostream>
#include <cstddef>

namespace matveev
{
struct ISeqProperty
{
  void operator()(int value)
  {
    next(value);
  }
  size_t operator()() const
  {
    return result();
  }
  virtual ~ISeqProperty() = default;
 private:
  virtual void next(int value) = 0;
  virtual size_t result() const = 0;
  };
struct CntProperty : public ISeqProperty
{
 private:
  void next(int) override
  {
    ++count;
  }
  size_t result() const override
  {
    return count;
  }
  size_t count = 0;
};
}

int main()
{
  int a = 0, count_max = 0, max_num = 0, previous = 0, count_rem = 0, len=0;
  matveev::CntProperty cnt;

  std::cin >> a;
  if (std::cin.fail())
  {
    std::cerr << "Error input" << std::endl;
    return 1;
  }
  max_num = a;
  if (a == 0)
  {
    std::cerr << "No numbers" << std::endl;
    return 2;
  }
  while (a != 0)
  {
    cnt(a);
    len++;
    if (a == max_num)
    {
      count_max++;
    }
    if (a > max_num)
    {
      max_num = a;
      count_max = 1;
    }

    if (previous != 0 && a % previous == 0)
    {
      count_rem++;
    }
    previous = a;
    std::cin >> a;
    if (std::cin.fail())
    {
      std::cerr << "Error input" << std::endl;
      return 1;
    }
  }
  if (len < 2)
  {
    std::cout << "CNT-MAX " << count_max << std::endl;
    std::cerr << "Error numbers" << std::endl;
    return 2;
  }
  std::cout << "CNT-MAX " << count_max << std::endl;
  std::cout << "DIV-REM " << count_rem << std::endl;
  return 0;
}

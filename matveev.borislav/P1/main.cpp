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

struct CntMaxProperty : public ISeqProperty
{
private:
  void next(int value) override
  {
    if (!has_value)
    {
      max = value;
      count = 1;
      has_value = true;
      return;
    }
    if (value > max)
    {
      max = value;
      count = 1;
    }
    else if (value == max)
    {
      ++count;
    }
  }

  size_t result() const override
  {
    return count;
  }

  int max = 0;
  size_t count = 0;
  bool has_value = false;
};
}

int main()
{
  int a = 0;
  int previous = 0;
  size_t count_rem = 0;

  matveev::CntProperty cnt;
  matveev::CntMaxProperty cnt_max;

  std::cin >> a;
  if (std::cin.fail())
  {
    std::cerr << "Error input" << std::endl;
    return 1;
  }

  if (a == 0)
  {
    std::cerr << "No numbers" << std::endl;
    return 2;
  }

  while (a != 0)
  {
    cnt(a);
    cnt_max(a);

    if (previous != 0 && a % previous == 0)
    {
      ++count_rem;
    }
    previous = a;

    std::cin >> a;
    if (std::cin.fail())
    {
      std::cerr << "Error input" << std::endl;
      return 1;
    }
  }

  if (cnt() < 2)
  {
    std::cout << "CNT-MAX " << cnt_max() << std::endl;
    std::cerr << "Error numbers" << std::endl;
    return 2;
  }

  std::cout << "CNT-MAX " << cnt_max() << std::endl;
  std::cout << "DIV-REM " << count_rem << std::endl;
  return 0;
}

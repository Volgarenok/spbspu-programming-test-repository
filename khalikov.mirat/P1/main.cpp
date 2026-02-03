#include <iostream>

struct ITrait
{
  virtual void operator()(int a) = 0;
  virtual size_t operator()() = 0;
  virtual ~ITrait() = default;
};

int main()
{}

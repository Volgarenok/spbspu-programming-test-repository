#ifndef KARHANIN_ITRAIT_HPP
#define KARHANIN_ITRAIT_HPP

namespace karhanin
{
  class ITrait
  {
  protected:
    int curValue = 0;
    int count = 0;
    const char* name = nullptr;
  public:
    virtual void operator()(int value) = 0;
    virtual int operator()() const = 0;
    virtual ~ITrait() = default;
    const char* getName() const;
  };
}
#endif
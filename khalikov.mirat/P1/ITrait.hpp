#ifndef ITRAIT_HPP
#define ITRAIT_HPP
namespace khalikov
{
  struct ITrait
  {
    virtual void operator()(int a) = 0;
    virtual int operator()() = 0;
    virtual ~ITrait() = default;
  };
}

#endif

#ifndef TRAITS_HPP
#define TRAITS_HPP
#include "virtual.hpp"
#include <cstddef>
#include <limits>

namespace traits
{
  struct grtLss: public ITrait
  {
    grtLss():
      count_(0),
      first_(std::numeric_limits<int>::min()),
      second_(std::numeric_limits<int>::min()),
      third_(std::numeric_limits<int>::min())
    {}
   private:
    void process(int a);
    size_t result() const;
    size_t count_;
    int first_, second_, third_;
  };

  struct monDec: public ITrait
  {
    monDec():
      tempCount_(1),
      mcount_(0),
      curr_(std::numeric_limits<int>::min()),
      prev_(std::numeric_limits<int>::min())
    {}
   private:
    void process(int a);
    size_t result() const;
    size_t tempCount_, mcount_;
    int curr_, prev_;
  };

  void traitCreate(ITrait *p[2]);
}

#endif

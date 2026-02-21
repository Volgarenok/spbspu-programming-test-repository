#ifndef TRAITS_HPP
#define TRAITS_HPP
#include "virtual.hpp"
#include <cstddef>

namespace traits
{
  struct grtLss : public ITrait
  {
    grtLss() : count_(0), first_(0), second_(0), third_(0), f_(0) {}
   private:
    void process(int a);
    size_t result() const;
    size_t count_;
    int first_, second_, third_, f_;
  };

  struct monDec : public ITrait
  {
    monDec() : tempCount_(0), mcount_(0), curr_(0), prev_(0), f_(0) {}
   private:
    void process(int a);
    size_t result() const;
    size_t tempCount_, mcount_;
    int curr_, prev_, f_;
  };

  void traitCreate(ITrait *p[2]);
}

#endif

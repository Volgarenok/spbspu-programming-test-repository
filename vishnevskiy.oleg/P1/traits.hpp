#ifndef TRAITS_HPP
#define TRAITS_HPP
#include "virtual.hpp"
#include <cstddef>

namespace traits
{
  struct grtLss : public ITrait
  {
    grtLss() = default;
   private:
    void process(int a);
    size_t result() const;
    size_t count_;
    int first_, second_, third_, f_;
  };

  struct monDec : public ITrait
  {
    monDec() = default;
   private:
    void process(int a);
    size_t result() const;
    size_t tempCount_, mcount_;
    int curr_, prev_, f_;
  };

  void traitCreate(ITrait *p[2]);
}

#endif

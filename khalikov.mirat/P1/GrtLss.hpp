#ifndef GRTLSS_HPP
#define GRTLSS_HPP

#include "ITrait.hpp"

namespace khalikov
{
  struct GrtLss: ITrait
  {
    GrtLss();
    void operator()(int a);
    int operator()();
    private:
      bool firstadd_;
      int k_;
      int prev_;
      int act_;
      int next_;
  };
}

#endif

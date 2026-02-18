#ifndef GRTLSS_HPP
#define GRTLSS_HPP
#include "ITrait.hpp"
#include <iostream>
namespace khalikov
{
  struct GrtLss
  {
    GrtLss();
    void operator()(int a);
    int operator()();
  private:
    size_t c_;
    int k_;
    int prev_;
    int act_;
    int next_;
  };
}

#endif

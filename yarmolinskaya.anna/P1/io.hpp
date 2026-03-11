#ifndef YARMOLINSKAYA_IO_HPP
#define YARMOLINSKAYA_IO_HPP

#include <istream>

namespace yarmolinskaya {

struct result_t {
  bool inputValid;
  bool subMaxValid;
  int subMax;
  int eqlSeq;
};

result_t compute(std::istream& in);

}

#endif

#include "itrait.h"

#ifndef INC_SEQ_H
#define INC_SEQ_H

struct IncSeq : ITrait
{
  IncSeq() : k_(0), prev_(0), n_(0) {}

private:
  void upd(int a) override;
  size_t result() const override;
  const char *name() const override;
  size_t k_;
  int prev_;
  size_t n_;
};

#endif

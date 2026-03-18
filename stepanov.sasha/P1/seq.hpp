#ifndef SEQ_HPP
#define SEQ_HPP
#include <cstddef>

namespace stepanov
{
  struct DivPrevSeq
  {
    DivPrevSeq();
    void update(int next);
    size_t result() const;

  private:
    int prev_;
    size_t count_;
    size_t inputs_;
  };

  struct SubMaxSeq
  {
    SubMaxSeq();
    void update(int next);
    int result() const;

  private:
    int max_;
    int sub_max_;
    size_t inputs_;
  };
}

#endif

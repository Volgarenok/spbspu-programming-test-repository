#ifndef SGN_CHG_HPP
#define SGN_CHG_HPP

namespace lukashevich
{
  class SignChangeCount
  {
    public:
      SignChangeCount();

      void countSGN(int currVal);
      int getCount() const;

    private:
      int count_;
      int prevVal_;
      bool hasPrev_;
  };
}
#endif

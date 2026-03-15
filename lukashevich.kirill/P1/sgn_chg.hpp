#ifndef SGN_CHG_HPP
#define SGN_CHG_HPP

namespace lukashevich
{
  class SignChangeCount
  {
    private:
    int count;
    int prevVal;
    bool hasPrev;

    public:
    SignChangeCount(): count(0),
      prevVal(0),
      hasPrev(false)
    {}

    void countSGN(int currVal);
    int getCount() const;
  };

}
#endif

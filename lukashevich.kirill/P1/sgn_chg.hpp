#ifndef SGN_CHG_HPP
#define SGN_CHG_HPP

namespace lukashevich
{
  class signChangeCount
  {
  private:
    int count;
    int prev_val;
    bool has_prev;

  public:
    signChangeCount(): count(0), prev_val(0), has_prev(false)
    {}

    void countSGN(int curr_val);
    int get_count() const;
  };

}
#endif

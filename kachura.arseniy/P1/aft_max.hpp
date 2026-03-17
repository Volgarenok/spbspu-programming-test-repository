namespace kachura
{
  class AftMax
  {
    int count_, max_;

    void step(int * num);
    int get_count();

    public:
      AftMax()
      {
        max_ = 0;
        count_ = 0;
      }
  };
}

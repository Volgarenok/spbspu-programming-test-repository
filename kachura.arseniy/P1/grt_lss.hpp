namespace kachura
{
  class GrtLss
  {
    int count_, max_;

    void step(int * num);
    int get_count();

    public:
      GrtLss()
      {
        max_ = 0;
        count_ = 0;
      }
  };
}
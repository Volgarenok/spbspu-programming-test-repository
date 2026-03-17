namespace kachura
{
  class GrtLss
  {
    int last_, central_, count_;

    void step(int * num);
    int get_count();

    public:
      GrtLss()
      {
        last_ = 0;
        central_ = 0;
        count_ = 0;
      }
  };
}

namespace kachura
{
  struct GrtLss
  {
    GrtLss()
    {
      last_ = 0;
      central_ = 0;
      count_ = 0;
      lenght_ = 0;
    }

    void step(int * num);
    int get_count();

    private:
      int last_, central_, count_, lenght_;
  };
}

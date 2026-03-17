namespace kachura
{
  struct AftMax
  {
    AftMax()
    {
      max_ = 0;
      count_ = 0;
    }

    void step(int * num);
    int get_count();

    private:
      int max_, count_;
  };
}

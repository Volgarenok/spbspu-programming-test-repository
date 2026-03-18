namespace kachura
{
  struct AftMax
  {
    AftMax():
     max_ (0),
     count_ (0),
     lenght_ (0)
    {}

    void step(int * const num);
    int getCount() const;

    private:
      int max_, count_, lenght_;
  };
}

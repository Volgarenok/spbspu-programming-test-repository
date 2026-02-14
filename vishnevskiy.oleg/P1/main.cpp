#include <iostream>

struct grtLss {
  grtLss();
  void push(int);
  size_t result() const;
 private:
  size_t count;
  int first, second, third;
};

struct monDec {
  monDec();
  void push(int);
  size_t result() const;
 private:
  size_t count;
  int curr, prev;
};

int main()
{
  int el = 0;
  grtLss g;
  monDec m;
  while (std::cin >> el)
  {
    g.push(el);
    m.push(el);
  }
  if (!std::cin.eof())
  {
    std::cerr << "Input failed\n";
    return 1;
  }
  std::cout << g.result() << " " << m.result() << "\n";
  return 0;
}



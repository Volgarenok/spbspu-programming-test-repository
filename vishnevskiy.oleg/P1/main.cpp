#include <iostream>

void append(int *a, int b, size_t &s);

int main()
{
  size_t n = 0;
  int seq = new int[1];
  int el = -1;
  std::cin>>el;
  seq[0] = el;
  std::cin>>el;
  while (el!=0)
  {
    append(seq, el, n);
  }
  if (std::cin.fail())
  {
    return 1;
  }
  if (n==1)
  {
    return 1;
  }
}


#include <iostream>

void append(int *&an, int b, size_t &s);

int main()
{
  size_t n = 1;
  int * seq = new int[1];
  int el = 0;
  std::cin>>el;
  seq[0] = el;
  std::cin>>el;
  while (el!=0)
  {
    append(seq, el, n);
    std::cin>>el;
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

void append(int *&an, int b, size_t &s)
{
  int * tempseq = new int[s+1];
  for (size_t i = 0; i<s; i++)
  {
    tempseq[i] = an[i];
  }
  tempseq[s] = b;
  s++;
  delete[] an;
  an = tempseq;
  tempseq = nullptr;
}

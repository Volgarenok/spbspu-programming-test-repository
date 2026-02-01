#include <iostream>

void append(int *&an, int b, size_t &s);
int monDec(int *a, size_t s);
int grtLss(int *a, size_t s);

int main()
{
  size_t n = 0;
  int * seq = new int[1];
  int el = 0;
  std::cin>>el;
  while (el!=0)
  {
    append(seq, el, n);
    std::cin>>el;
  }
  if (std::cin.fail())
  {
    std::cerr<<"Input failed\n";
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

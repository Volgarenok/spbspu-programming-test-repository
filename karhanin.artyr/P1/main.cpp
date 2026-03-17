#include <iostream>
#include "evenseqcounter.hpp"
#include "incseqcounter.hpp"
#define SIZE 2

void free_memory(karhanin::ITrait** ptrArray)
{
  std::cout << "Clearing memory\n";
  for (int i = 0; i < SIZE; i++)
  {
    delete ptrArray[i];
  }
  delete[] ptrArray;
}
int main()
{
  int num;
  int length = 0;
  karhanin::ITrait** ptrArray = nullptr;
  try{
    ptrArray = new karhanin::ITrait * [2];
    ptrArray[0] = new karhanin::IncSeqCounter;
    ptrArray[1] = new karhanin::EvenSeqCounter;
  }catch(const std::bad_alloc& e){
    std::cerr << "Bad_alloc\n";
    free_memory(ptrArray);
    return 2;
  }
  while (std::cin >> num)
  {
    for (int i = 0; i < SIZE; i++)
    {
      (*ptrArray[i])(num);
    }
    if (num == 0) { break; }
      length++;
  }
  if (std::cin.fail())
  {
    std::cerr << "Bad sequence\n";
    free_memory(ptrArray);
    return 1;
  }
  if (length == 0 || length == 1)
  {
    std::cerr << "The sequence is too short\n";
    free_memory(ptrArray);
    return 2;
  }
  for (int i = 0; i < SIZE; i++)
  {
    std::cout << (*ptrArray[i]).getName() << (*ptrArray[i])() << "\n";
  }
  free_memory(ptrArray);
  return 0;
}

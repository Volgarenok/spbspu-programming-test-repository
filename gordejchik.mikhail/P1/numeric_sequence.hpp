#ifndef NUMERIC_SEQUENCE_HPP
#define NUMERIC_SEQUENCE_HPP

#include <cstddef>

namespace gordejchik
{
  struct EvenCount
  {
    size_t maxEvenCount;
    size_t currentEvenCount;
    size_t totalNumbers;

    EvenCount();
    void update(int number);
    size_t getResult() const;
  };

  struct LocalMax
  {
    size_t localMaxCount;
    int previousNumber;
    int currentNumber;
    int nextNumber;
    size_t totalNumbers;

    LocalMax();
    void update(int number);
    size_t getResult() const;
  };

  void printResults(const EvenCount& evenCount, const LocalMax& localMax);
}

#endif

#include <iostream>
#include <limits>
#include <stdexcept>

namespace sadovnik
{

struct SequenceResults
{
  bool subMaxValid;
  int subMaxValue;
  bool aftMaxValid;
  int aftMaxValue;
};

SequenceResults processSequence(std::istream& input)
{
  int totalElements = 0;
  int currentNumber = 0;

  int firstMax = std::numeric_limits<int>::min();
  int secondMax = std::numeric_limits<int>::min();

  int maxVal = 0;
  int firstMaxIndex = 0;
  int countAfterMax = 0;
  bool aftMaxInitialized = false;
  int index = 0;

  while (true)
  {
    if (!(input >> currentNumber))
    {
      throw std::runtime_error("Invalid input");
    }
    if (currentNumber == 0)
    {
      break;
    }

    ++totalElements;

    if (totalElements == 1)
    {
      firstMax = currentNumber;
    }
    else
    {
      if (currentNumber > firstMax)
      {
        secondMax = firstMax;
        firstMax = currentNumber;
      }
      else if (currentNumber > secondMax)
      {
        secondMax = currentNumber;
      }
      else if (currentNumber == firstMax && secondMax < firstMax)
      {
        secondMax = currentNumber;
      }
    }

    if (!aftMaxInitialized)
    {
      maxVal = currentNumber;
      firstMaxIndex = index;
      countAfterMax = 0;
      aftMaxInitialized = true;
    }
    else
    {
      if (currentNumber > maxVal)
      {
        maxVal = currentNumber;
        firstMaxIndex = index;
        countAfterMax = 0;
      }
    }

    if (aftMaxInitialized && index > firstMaxIndex)
    {
      ++countAfterMax;
    }

    ++index;
  }

  SequenceResults res;
  res.aftMaxValid = (totalElements >= 1);
  if (res.aftMaxValid)
  {
    res.aftMaxValue = countAfterMax;
  }
  else
  {
    res.aftMaxValue = 0;
  }

  res.subMaxValid = (totalElements >= 2);
  if (res.subMaxValid)
  {
    res.subMaxValue = secondMax;
  }
  else
  {
    res.subMaxValue = 0;
  }

  return res;
}

}

int main()
{
  try
  {
    sadovnik::SequenceResults res = sadovnik::processSequence(std::cin);

    bool outputAnything = false;

#ifdef SUB_MAX
    if (res.subMaxValid)
    {
      std::cout << res.subMaxValue << '\n';
      outputAnything = true;
    }
#endif

#ifdef AFT_MAX
    if (res.aftMaxValid)
    {
      std::cout << res.aftMaxValue << '\n';
      outputAnything = true;
    }
#endif

#ifndef SUB_MAX
#ifndef AFT_MAX
    if (res.subMaxValid)
    {
      std::cout << res.subMaxValue << '\n';
      outputAnything = true;
    }
    if (res.aftMaxValid)
    {
      std::cout << res.aftMaxValue << '\n';
      outputAnything = true;
    }
#endif
#endif

    if (!outputAnything)
    {
      std::cerr << "Empty sequence\n";
      return 2;
    }

    bool allValid = true;
#ifdef SUB_MAX
    if (!res.subMaxValid) allValid = false;
#endif
#ifdef AFT_MAX
    if (!res.aftMaxValid) allValid = false;
#endif
#ifndef SUB_MAX
#ifndef AFT_MAX
    if (!res.subMaxValid || !res.aftMaxValid) allValid = false;
#endif
#endif

    if (!allValid)
    {
      std::cerr << "Not enough elements for some characteristics\n";
      return 2;
    }

    return 0;
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch (...)
  {
    std::cerr << "Unexpected error\n";
    return 1;
  }
}

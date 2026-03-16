#ifndef SEQ_HPP
#define SEQ_HPP

namespace yarmolinskaya {
  int updateSubMax(int value, int maxVal, int &secondMax, bool &hasSecond);
  void updateEqlSeq(int value, int prev, int &currentRun, int &maxRun);
}

#endif

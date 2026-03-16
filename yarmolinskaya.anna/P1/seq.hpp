#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

namespace yarmolinskaya {
  int updateSubMax(int value, int maxVal, int &secondMax, bool &hasSecond);
  void updateEqlSeq(int value, int prev, int &currentRun, int &maxRun);
}

#endif

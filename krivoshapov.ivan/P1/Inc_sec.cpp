#include "Inc_sec.h"

void IncSeq::upd(int a) {
    if (n_ > 0 && a > prev_) {
        ++k_;
    }
    prev_ = a;
    ++n_;
}

size_t IncSeq::result() const {
    return k_;
}

const char * IncSeq::name() const {
    return "inc-seq";
}

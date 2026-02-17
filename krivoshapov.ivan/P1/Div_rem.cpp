#include "Div_rem.h"

void DivRem::upd(int a) {
    if (n_ > 0 && prev_ != 0 && a % prev_ == 0) {
        ++k_;
    }
    prev_ = a;
    ++n_;
}

size_t DivRem::result() const {
    if (!valid()) {
        throw "sequence is too short";
    }
    return k_;
}

const char * DivRem::name() const {
    return "div-rem";
}
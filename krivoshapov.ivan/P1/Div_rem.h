#include "Itrait.h"

#ifndef DIV_REM_H
#define DIV_REM_H

struct DivRem : ITrait {
    DivRem(): k_(0), prev_(0), n_(0) {}
    bool valid() const {
        return n_ >= 2;
    }
private:
    void upd(int a) override;
    size_t result() const override;
    const char * name() const override;
    size_t k_;
    int    prev_;
    size_t n_;
};

#endif

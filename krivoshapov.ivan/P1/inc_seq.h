#include "itrait.h"

// =========================================================
// COMMIT 2: "Add IncSeq functor header"
// =========================================================
//
// Пункт 2: каждая характеристика реализует интерфейс
//          в собственном классе
//
// [INC-SEQ] Определить, сколько элементов последовательности
// больше предыдущего элемента.
//
// Пример: 1 2 3 -2 -1 0  =>  3
//         1 0             =>  0
//         0               =>  0

#ifndef INC_SEQ_H
#define INC_SEQ_H

struct IncSeq : ITrait {
    IncSeq(): k_(0), prev_(0), n_(0) {}
private:
    void upd(int a) override;
    size_t result() const override;
    const char * name() const override;
    size_t k_;
    int    prev_;
    size_t n_;
};

#endif

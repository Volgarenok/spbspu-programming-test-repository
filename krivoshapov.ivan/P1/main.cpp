#include <iostream>

struct ITrait {
    void operator()(int a) {
        upd(a);
    }
    size_t operator()() const {
        return result();
    }
    const char *trait() const {
        return name();
    }
    virtual ~ITrait() = default;
private:
    virtual void upd(int) = 0;
    virtual size_t result() const = 0;
    virtual const char *name() const = 0;
};

struct IncSeq : ITrait {
    IncSeq(): k_(0), prev_(0), n_(0) {}
private:
    void upd(int a) {
        if (n_ > 0 && a > prev_){
            ++k_;
        }
        prev_ = a;
        ++n_;
    }
    size_t result() const {
        return k_;
    }
    const char *name() const {
        return "inc-seq";
    }
    size_t k_;
    int prev_;
    size_t n_;
};

struct DivRem : ITrait {
    DivRem(): k_(0), prev_(0), n_(0) {}
    bool valid() const {
        return n_ >=2;
    }
private:
    void upd(int a) {
        if(n_ > 0 && prev_ != 0 && a%prev_ == 0) {
            ++k_;
        }
        prev_ = a;
        ++n_;
    }
    size_t result() const {
        return k_;
    }
    const char *name() const {
        return "div-rem";
    }
    size_t k_;
    int prev_;
    size_t n_;
};

int main(){
    int error = 0;
    int a = 0;
    IncSeq inc_seq;
    DivRem div_rem;
    while (std::cin >> a) {
        if (a==0) {
            break;
        }
        inc_seq(a);
        div_rem(a);
    }
    if (!std::cin.eof() && std::cin.fail()){
        std::cerr << "Bad input\n";
        return 1;
    }
    if (!div_rem.valid()) {
        std::cerr << div_rem.trait() << ": sequences is too short\n";
        error = 2;
    }
    using std::cout;
    cout << inc_seq.trait() << ": " << inc_seq() << "\n";
    if (div_rem.valid()) {
        cout << div_rem.trait() << ": " << div_rem() << "\n";
    }
    return error;
}

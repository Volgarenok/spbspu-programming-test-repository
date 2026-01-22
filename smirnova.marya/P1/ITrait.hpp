#ifndef ITRAIT_HPP
#define ITRAIT_HPP

class ITrait {
public:
    virtual ~ITrait() = default;
    bool add(int value)
    {
        return do_add(value);
    }
    virtual int value() const = 0;
    virtual bool computable() const = 0;
protected:
    virtual bool do_add(int value) = 0;
};

#endif

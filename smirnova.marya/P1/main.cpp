#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <climits>

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

class MaxIncreasing final : public ITrait {
public:
    MaxIncreasing() : last(0), current(0), maximum(0), hasValue(false) {}
protected:
    bool do_add(int value) override {
        if (!hasValue) {
            last = value; 
            current = maximum = 1; 
            hasValue = true;
            return false;
        }
        if (value > last)
            current++;
        else
            current = 1;
        if (current > maximum)
            maximum = current;
        last = value;
        return true;
    }
public:
    int value() const override
    {
        return maximum;
    }
    bool computable() const override
    {
        return hasValue;
    }
private:
    int last, current, maximum;
    bool hasValue;
};

class PythagoreanTriples final : public ITrait {
public:
    PythagoreanTriples() : a(0), b(0), count(0), size(0) {}
protected:
    bool do_add(int value) override
    {
        if (size == 0) {
            a = value;
            size = 1;
            return false;
        }
        if (size == 1) {
            b = value;
            size = 2;
            return false;
        }
        if (pyCheck(a, b, value))
            ++count;
        a = b;
        b = value;
        size = 3;
        return true;
    }
public:
    int value() const override
    {
        return count;
    }
    bool computable() const override
    {
        return size >= 3;
    }
private:
    int a = 0, b = 0, size = 0;
    int count;
    bool pyCheck(int x, int y, int z) const
    {
        if (x <= 0 || y <= 0 || z <= 0)
            return false;

        if (x > INT_MAX / x || y > INT_MAX / y || z > INT_MAX / z)
            return false;

        return x*x + y*y == z*z || 
               x*x + z*z == y*y || 
               y*y + z*z == x*x;
    }
};

ITrait* get_prop(const std::string& name)
{
    if (name == "1")
        return new MaxIncreasing();
    if (name == "2")
        return new PythagoreanTriples();
    return nullptr;
}

int input(ITrait** traits, int traitCount)
{
    int x;
    int totalAdded = 0;

    while (std::cin >> x)
    {
        if (x == 0) {
            while (std::cin.peek() == ' ' || std::cin.peek() == '\t')
                std::cin.get();
            int next = std::cin.peek();
            if (next == '\n') {
                if (totalAdded == 0) {
                    std::cerr << "Error: сannot identify sequence\n";
                    return 2;
                }
                return 0;
            }
        }
        for (int i = 0; i < traitCount; ++i)
            traits[i]->add(x);
        totalAdded++;
    }

		if (std::cin.fail()) {
        std::cerr << "Error: failed to read data\n";
        return 1;
    }

    return 0;
}

void output(ITrait** traits, int traitCount)
{
    bool errorOccurred = false;
    for (int i = 0; i < traitCount; ++i)
    {
        if (traits[i] && traits[i]->computable()) {
            std::cout << i + 1 << " characteristic: " << traits[i]->value() << "\n";
        } else {
            std::cout << i + 1 << " characteristic: not enough data\n";
            errorOccurred = true;
        }
    }
}

int main() {
    const int traitCount = 2;
    ITrait** traits = nullptr;

    try {
        traits = new ITrait*[traitCount];
        for (int i = 0; i < traitCount; ++i)
            traits[i] = nullptr;

        for (int i = 0; i < traitCount; ++i)
        {
            traits[i] = get_prop(std::to_string(i + 1));
            if (!traits[i])
                std::cerr << "Error: failed to create array\n";
                return 2;
        }

        input(traits, traitCount);
        output(traits, traitCount);

        for (int i = 0; i < traitCount; ++i)
            delete traits[i];
        delete[] traits;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
        if (traits) {
            for (int i = 0; i < traitCount; ++i)
                delete traits[i];
            delete[] traits;
        }
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        if (traits) {
            for (int i = 0; i < traitCount; ++i)
                delete traits[i];
            delete[] traits;
        }
        return 2;
    }

    return 0;
}

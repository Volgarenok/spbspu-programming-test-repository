#include <vector>
#include <iostream>

int count_increasing(const int* numbers, std::size_t size) 
{
    if (size <= 1) {
        return 0;
    }
    int count = 0;

    for (std::size_t i = 1; i < size; i++) 
    {
        if (numbers[i] > numbers[i - 1]) 
        {
            count++;
        }
    }

    return count;
}

int main() 
{
    std::vector <int> numbers;
    int num;
    while (std::cin >> num && num != 0) 
    {
        numbers.push_back(num);
    }
    if (std::cin.fail() && !std::cin.eof()) 
    {
        std::cerr << "Input error";
       return 1;
    }
    std::cout << count_increasing(numbers.data(), numbers.size());
    return 0;
}

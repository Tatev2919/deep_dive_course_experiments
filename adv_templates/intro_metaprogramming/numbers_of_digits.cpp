#include <iostream>

template <int a>

struct num_of_digits {
    static const int res = num_of_digits<a / 10>::res + 1;
};

template <>
struct num_of_digits<0> {  
    static const int res = 0;
};

int main()
{
    std::cout << num_of_digits<6788842>::res << std::endl;

    return 0;
}

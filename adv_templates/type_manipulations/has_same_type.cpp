#include <iostream>

template <typename T>
constexpr bool is_same(const T& a, const T& b)
{
    return true;
}

template <typename T, typename U>
constexpr bool is_same(const T& a, const U& b)
{
    return false;
}

int main()
{
    int x, y;
    float b;
    std::cout<<is_same(x, y)<<std::endl;
    std::cout<<is_same(x, b)<<std::endl;
    return 0;
}

#include <iostream>

template <typename T>
struct extend
{
    static const int res = 1;
};

template <typename type, int n>
struct extend<type[n]>
{
    static const int res = n;
};

int main()
{
    int matrix[5][7];
    std::cout<<extend<decltype(matrix)>::res<<std::endl;

    return 0;
}

#include <iostream>

template <typename T>
struct rank
{
    static const int res = 0;
};

template <typename type, int n>
struct rank<type[n]>
{
    static const int res = rank<type>::res + 1;
};


int main()
{
    int matrix[5][7][8][3][2];
    std::cout<<rank<decltype(matrix)>::res;

    return 0;
}

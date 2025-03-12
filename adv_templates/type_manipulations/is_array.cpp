#include <iostream>

template <typename T>
struct is_array
{
    static const bool res = 0;
};

template <typename type, int n>
struct is_array<type[n]>
{
    static const bool res = true;
};

int main()
{
    int arr[5];
    int matrix[5][7];
    int x;
    std::cout<<is_array<decltype(arr)>::res<<std::endl;
    std::cout<<is_array<decltype(matrix)>::res<<std::endl;
    return 0;
}

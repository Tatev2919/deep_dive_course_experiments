#include <iostream>

template <typename T>
struct is_pointer
{
    static const bool res = false;
};

template <typename type>
struct is_pointer<type*>
{
    static const bool res = true;
};

int main()
{
    int*** ptr = NULL;
    int x;
    std::cout<<is_pointer<decltype(ptr)>::res<<std::endl;
    std::cout<<is_pointer<decltype(x)>::res<<std::endl;
    return 0;
}

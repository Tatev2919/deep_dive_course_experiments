#include <iostream>

template <int a, int n>
struct pow {
    static const int res = a * pow< a, n-1>::res;
};

template <int a>
struct pow<a, 0> {
    static const int res = 1;
};


int main()
{
    int a = 2;
    
    std::cout << pow<2,3>::res << std::endl;

    return 0;
}

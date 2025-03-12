#include <iostream>

template <int a, int n>
struct pow {
    static const int h = pow<a, n/2>::res;
    static const int res = (n%2 == 0)? h*h :  a * h * h;
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

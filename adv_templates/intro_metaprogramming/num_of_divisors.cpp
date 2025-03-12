#include <iostream>

template <int a, int i>
struct number_of_divisors_ {
    static const int res = (a%i == 0) ? number_of_divisors_<a, i-1>::res + 1: number_of_divisors_<a, i-1>::res;
};

template <int a>
struct number_of_divisors_<a,1> {
    static const int res = 1;
};

template <int a>
struct number_of_divisors {
    static const int res = number_of_divisors_<a,a>::res;
};

int main()
{
    std::cout<< number_of_divisors<25>::res << std::endl;
    std::cout<< number_of_divisors<6>::res << std::endl;
    return 0;
}

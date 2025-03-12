#include <iostream>


template <int a>
struct module {
    static const int res = (a >= 0) ? a : -a;
};


int main()
{
    std::cout << module<-1>::res << std::endl;

    return 0;
}

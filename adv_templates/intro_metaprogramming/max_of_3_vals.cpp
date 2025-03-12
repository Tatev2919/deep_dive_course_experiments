#include <iostream>

template <int a, int b>
struct max_of_2_vals {
    static const int res = (a > b) ? a: b;  
};

template <int a, int b, int c>
struct max_of_3_vals {
    static const int res = max_of_2_vals<max_of_2_vals<a,b>::res, c>::res;
};

int main()
{
    std::cout << max_of_3_vals<1,2,3>::res << std::endl;
    std::cout << max_of_3_vals<-10, 25, 7>::res << std::endl;
    
    return 0;
}

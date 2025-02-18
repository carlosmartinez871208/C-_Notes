#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

int main (int argc, char** argv)
{
    unsigned char var0 {55};
    unsigned char var1 {130};
    unsigned char var2 {131};
    int x;
    int units {10};
    int sum;
    double y {45.44};
    double price {45.6};
    double m {12.5};
    double n {34.6};

    /* Implicit convertion */
    double total_price = price * units;
    std::cout << " Precio total:  " << total_price << std::endl;

    /* Implicit narrowing convertion */
    x = y;
    std::cout << " El valor de x: " << x << std::endl;

    /* Explicit convertion */
    sum = static_cast<int> (m+n);
    std::cout << " El valor de sum: " << sum << std::endl;

    /* Overflow */
    var0 = var1 + var2;
    std::cout << " El valor de var0: " << static_cast<int>(var0) << std::endl;

    /* Underflow */
    var0 = var1 - var2;
    std::cout << " El valor de var0: " << static_cast<int>(var0) << std::endl;

    return EXIT_SUCCESS;
}
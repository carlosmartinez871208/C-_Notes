#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

int main (int argc, char** argv)
{
    int Num1 = 1;
    unsigned Num2 {3};
    signed Num3 {-10};
    /* Se imprimen cada de una de las variables */
    std::cout << " Variable Num1 = " << Num1 << std::endl;
    std::cout << " Variable Num2 = " << Num2 << std::endl;
    std::cout << " Variable Num3 = " << Num3 << std::endl;

    /* Se imprimen el tamaño de las variables */
    std::cout << "Size of Num1: " << sizeof(Num1) << std::endl;
    std::cout << "Size of int type: " << sizeof(int) << std::endl;
    return EXIT_SUCCESS;
}
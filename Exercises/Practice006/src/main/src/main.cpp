#include <iomanip>
#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

int main (int argc, char** argv)
{
    float Num1 {1.12345678901234567890f};
    double Num2 {1.12345678901234567890};
    long double Num3 {1.12345678901234567890L};
    /* Se imprimen cada de una de las variables */
    std::cout << std::setprecision(20);
    std::cout << " Variable Num1 = " << Num1 << std::endl;
    std::cout << " Variable Num2 = " << Num2 << std::endl;
    std::cout << " Variable Num3 = " << Num3 << std::endl;

    /* Se imprimen el tamaño de las variables */
    std::cout << "Size of float: " << sizeof(float) << std::endl;
    std::cout << "Size of double: " << sizeof(double) << std::endl;
    std::cout << "Size of long double: " << sizeof(long double) << std::endl;
    return EXIT_SUCCESS;
}
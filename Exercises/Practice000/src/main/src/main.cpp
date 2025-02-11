#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

int main (int argc, char** argv)
{
    int Num1 = 12;
    int Num2 = 9;
    int Sum = Num1 + Num2;
    std::cout << "Sum of two numbers is: " << Sum <<std::endl;
    return EXIT_SUCCESS;
}

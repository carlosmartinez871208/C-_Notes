#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

/* Sum function definition */
int Sum (int Num1, int Num2);

/* Display result funcion definition */
void printResult (int result);

int main (int argc, char** argv)
{
    int result = Sum(12,9);
    printResult (result);
    return EXIT_SUCCESS;
}

/* Sum function implementation */
int Sum (int Num1, int Num2)
{
    return (Num1 + Num2);
}

/* Display sum result in console */
void printResult (int result)
{
    std::cout << "Sum of two numbers is: " << result <<std::endl;
}
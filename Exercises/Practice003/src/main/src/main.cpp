#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

int main (int argc, char** argv)
{
    int Num1 = 15;       /* Representacion decimal */
    int Num2 = 017;      /* Representacion octal */
    int Num3 = 0xF;      /* Representacion hexadecimal */
    int Num4 = 0b1111;   /* Representacion binaria */

    /* Se imprimen cada de una de las variables */
    std::cout << " Variable Num1 = " << Num1 << std::endl;
    std::cout << " Variable Num2 = " << Num2 << std::endl;
    std::cout << " Variable Num3 = " << Num3 << std::endl;
    std::cout << " Variable Num4 = " << Num4 << std::endl;
    /* Lo anterior solo imprime 15 en cada linea por que la representacion en memoria es el mismo valor */
    return EXIT_SUCCESS;
}
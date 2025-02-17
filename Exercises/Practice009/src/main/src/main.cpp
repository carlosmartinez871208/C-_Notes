#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

int Sum (int a, int b);
int Subtract (int a, int b);
int Multiplication (int a, int b);
int* Division (int a, int b);

int main (int argc, char** argv)
{
    int Num1;
    int Num2;
    int* Res = nullptr;
    std::cout << "Ingresa primer numero: " << std::endl;
    std::cin >> Num1;
    std::cout << "Ingresa segundo numero: " << std::endl;
    std::cin >> Num2;
    std::cout << "El resultado de la suma es: " << Sum (Num1,Num2) << std::endl;
    std::cout << "El resultado de la resta es: " << Subtract (Num1,Num2) << std::endl;
    std::cout << "El resultado de la multiplicacion es: " << Multiplication (Num1,Num2) << std::endl;
    if(Num2 != 0)
    {
        Res = Division(Num1, Num2);
        std::cout << "El resultado de la division es: " << *Res <<std::endl;
        std::cout << "El residuo de la division es: " << *(Res+1) <<std::endl;
    }
    else
    {
        std::cout << "Denominador debe ser diferente de 0" << std::endl;
    }

    return EXIT_SUCCESS;
}

int Sum (int a, int b)
{
    return (a + b);
}

int Subtract (int a, int b)
{
    return (a - b);
}

int Multiplication (int a, int b)
{
    return (a * b);
}

int* Division (int a, int b)
{
    int* Res = new int;
    *Res = a/b;
    *(Res+1) = a%b;
    return Res;
}
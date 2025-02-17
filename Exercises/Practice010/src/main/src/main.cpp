#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

/* constinit */
constinit int age = 37;
const constinit double weight (80.456);

int main (int argc, char** argv)
{
    /* Static assert */
    static_assert(03301 == 1729);

    /* Literales */
    const int answer = 42;      /* constant integer literal */
    double d = 108.87;     /* floating point literal passed to sin function */
    bool b = true;              /* boolean literal */

    /* Constant expressions */
    constexpr int goals {3};
    constexpr double Pi {3.14159};

    std::cout << "const int literal: " << answer << std::endl;
    std::cout << "double literal: " << d << std::endl;
    std::cout << "boolean literal: " << b << std::endl;
    std::cout << "int constant expression: " << goals << std::endl;
    std::cout << "double constant expression: " << Pi << std::endl;
    std::cout << "int constinit: " << age << std::endl;
    std::cout << "double const constinit: " << weight << std::endl;

    return EXIT_SUCCESS;
}
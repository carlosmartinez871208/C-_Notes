#include <iostream>
#include <string>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

int main (int argc, char** argv)
{
    char value = 65; /* ASCII character for 'A' */
    std::string phrase {"Hello"};
    std::cout << "value: " << value << std::endl;
    std::cout << "value (int): " << static_cast<int>(value) << std::endl;
    std::cout << "value: " << phrase << std::endl;
    return EXIT_SUCCESS;
}
#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

consteval int get_value()
{
    return 3u;
}

int main(void)
{
    std::cout << "Hello World!" << std::endl;
    return EXIT_SUCCESS;
}

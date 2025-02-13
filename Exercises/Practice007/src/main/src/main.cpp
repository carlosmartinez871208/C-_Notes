#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

int main (int argc, char** argv)
{
    bool red_light {true};
    bool green_light {false};

    if (red_light)
    {
        std::cout << "Stop!" << std::endl;
    }
    else
    {
        std::cout << "Go throught!" << std::endl;
    }

    if (green_light)
    {
        std::cout << "Go throught!" << std::endl;
    }
    else
    {
        std::cout << "Stop!" << std::endl;
    }
    return EXIT_SUCCESS;
}
#include <cstdlib>
#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

int main (int argc, char** argv)
{
    int age = 0;
    std::string name = "name";
    /* Statements to get a name and store it into a string variable */
    std::cout << "Please enter your name: " << std::endl;
    std::getline(std::cin,name);
    /* Statements to get age and store it  into a int variable */
    std::cout << "Please enter you age: " << std::endl;
    std::cin >> age;
    /* Statement to show name and age */
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
    return EXIT_SUCCESS;
}
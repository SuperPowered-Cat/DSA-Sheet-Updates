#include <iostream>
int main()
{
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;
    if (age >= 18)
    {
        std::cout << "You are legal.";
    }
    else
    {
        std::cout << "Beware of Drake.";
    }

    return 0;
}
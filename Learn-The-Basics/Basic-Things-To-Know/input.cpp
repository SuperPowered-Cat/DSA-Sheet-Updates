#include <iostream>
int main()
{
    int x;
    int y;
    std::cout << "Enter number 1: ";
    std::cin >> x;
    std::cout << "\n"
              << "Enter number 2: ";
    std::cin >> y;
    int sum = x + y;
    std::cout << "The sum of " << x << " and " << y << " is " << sum;

    return 0;
}
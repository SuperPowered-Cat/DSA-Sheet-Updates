#include <iostream>

int main()
{
    std::cout << "Enter number between 1-7 (corresponding to weekday) : ";
    int n;
    std::cin >> n;

    switch (n)
    {
    case 1:
        std::cout << "Monday";
        break;
    case 2:
        std::cout << "Tuesday";
        break;
    case 3:
        std::cout << "Wednesday";
        break;
    case 4:
        std::cout << "Thursday";
        break;
    case 5:
        std::cout << "Friday";
        break;
    case 6:
        std::cout << "Saturday";
        break;
    case 7:
        std::cout << "Sunday";
        break;
    default:
        std::cout << "Invalid";
        break;
    }

    return 0;
}
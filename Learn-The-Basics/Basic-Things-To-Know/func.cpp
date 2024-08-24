// modularity
// readability
// reusability
// void parameterised non-parameterised

#include <iostream>
using namespace std;
void printName(string s)
{
    std::cout << "Hello world!" << s;
}

int main()
{
    string x;
    // int x;
    getline(cin, x);
    printName(x);
    return 0;
}
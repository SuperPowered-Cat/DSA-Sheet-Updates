#include <iostream>
using namespace std;

// pass by value
void incr(int x)
{
    cout << x << endl;
    x += 1;
    cout << x << endl;
    x += 1;
}

// pass by reference
void incr2(int &x)
{
    cout << x << endl;
    x += 1;
    cout << x << endl;
    x += 1;
}

int main()
{
    int x;
    cin >> x;
    incr(x);
    cout << x << endl;
    incr2(x);
    cout << x << endl;

    return 0;
}
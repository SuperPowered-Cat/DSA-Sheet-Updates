#include <iostream>
#include <math.h>

using namespace std;

int maximum(int a, int b)
{
    if (a >= b)
        return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    // cout << min(a, b);
    // cout << max(a, b);
    int x = maximum(a, b);
    cout << x;
    return 0;
}
#include <iostream>
using namespace std;

int sum(int x, int y)
{
    return x + y;
}

int main()
{
    int a, b;
    int ans;
    cin >> a >> b;
    ans = sum(a, b);
    cout << "\n"
         << ans;
    return 0;
}
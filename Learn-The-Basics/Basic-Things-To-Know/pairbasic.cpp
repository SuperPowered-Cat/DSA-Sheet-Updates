#include <iostream>
using namespace std;
int main()
{

    pair<int, int> x = {1, 2};
    cout << x.second << endl;
    pair<int, pair<int, int>> y = {1, {6, 10}};
    cout << y.first << " " << y.second.first << " " << y.second.second << endl;
    pair<int, int> arr[] = {{2, 5}, {10, 20}, {80, 12}};
    cout << arr[1].second << endl;
}
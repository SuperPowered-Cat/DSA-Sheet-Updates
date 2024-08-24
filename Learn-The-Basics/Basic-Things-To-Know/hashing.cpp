#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // precomputation
    int hash[13] = {0};
    for (int i = 0; i < n; i++)
        hash[arr[i]] += 1;

    int totalNum;
    cin >> totalNum;
    while (totalNum > 0)
    {
        int currNum;
        cin >> currNum;
        cout << hash[currNum] << endl;
        totalNum--;
    }

    return 0;
}
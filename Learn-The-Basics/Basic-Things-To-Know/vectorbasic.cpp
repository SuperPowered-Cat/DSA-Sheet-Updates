#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    int x;

    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
    {
        cout << *(i) << " ";
    }

    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *(i) << " ";
    }
    // cout << *(i) << " ";
    // i++;
    // cout << *(i) << " ";
    // i++;
    // cout << *(i) << " ";

    v.erase(v.begin());
    v.erase(v.begin(), v.end() - 1);

    return 0;
}
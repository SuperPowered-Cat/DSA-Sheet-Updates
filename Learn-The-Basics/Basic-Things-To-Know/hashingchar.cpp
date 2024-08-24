#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int hash[256] = {0};
    for (int i = 0; i < s.size(); i++)
        hash[s[i]]++;

    int totalNum;
    cin >> totalNum;

    while (totalNum > 0)
    {
        char c;
        cin >> c;

        cout << hash[c];
        totalNum--;
    }
}
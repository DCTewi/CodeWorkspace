#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> o, j;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] - '0') & 1)
            {
                j.emplace_back(i);
            }
        }

        if (j.size() >= 2)
        {
            cout << s[j[0]] << s[j[1]] << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}
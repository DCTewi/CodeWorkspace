#include <bits/stdc++.h>
using namespace std;

int dic[15], big[15];

inline int c2i(char ch)
{
    return ch - '0';
}

int main()
{
    ios::sync_with_stdio(0);

    int n; cin >> n;
    string s; cin >> s;
    for (int i = 1; i <= 9; i++)
    {
        cin >> dic[i];
        if (dic[i] >= i)
        {
            big[i] = 1;
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        int x = c2i(s[i]);
        if (dic[x] > x)
        {
            for (int j = i; j < s.size() && big[c2i(s[j])]; j++)
            {
                s[j] = dic[c2i(s[j])] + '0';
            }
            break;
        }
    }

    cout<<s<<"\n";

    return 0;
}
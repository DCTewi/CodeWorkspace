#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s, ss;
queue<int> ans;

int main()
{
    ios::sync_with_stdio(false);

    cin>>s;

    for (int i = 0; i <= s.size(); i++)
    {
        int asc = s[i], len = 0;
        while (asc)
        {
            if (asc & 1)
            {
                ss += "1";
            }
            else
            {
                ss += "0";
            }
            asc >>= 1;
            len++;
        }
        for (; len < 8 && len; len++) ss += "0";
    }

    for (int i = 0; i < ss.size() / 6; i++)
    {
        int k = 0;
        for (int j = 0; j < 6; j++)
        {
            k <<= 1;
            if (ss[i * 6 + j] == '1')
            {
                k += 1;
            }
        }
        ans.push(k);
    }

    while (ans.size())
    {
        cout<<ans.front();
        ans.pop(); cout<<(ans.size()? " ": "");
    }

    return 0;
}
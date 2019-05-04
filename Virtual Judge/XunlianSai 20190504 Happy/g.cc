#include <bits/stdc++.h>
using namespace std;

set<char> ext;
queue<int> plc;

int main()
{
    string s; cin >> s;

    if (s.size() > 26)
    {
        return 0 * puts("IMPOSSIBLE");
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (ext.count(s[i]))
        {
            plc.push(i);
        }
        else
        {
            ext.emplace(s[i]);
        }
    }

    string ans = s;
    int cnt = plc.size();
    while (plc.size())
    {
        int now = plc.front(); plc.pop();

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (!ext.count(ch))
            {
                ans[now] = ch;
                ext.emplace(ch);
                cnt--;
                break;
            }
        }
    }

    if (!cnt)
    {
        cout << ans << "\n";
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
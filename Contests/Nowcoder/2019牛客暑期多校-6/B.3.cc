#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char toHex(string &strBin)
{
    char strHex;
    int base = 1, now = 0;
    for (int i = strBin.size() - 1; i >= 0; i--)
    {
        now += (strBin[i] - '0') * base;
        base <<= 1;
    }
    if (now < 10) strHex = now + '0';
    else strHex = now - 10 + 'a';

    return strHex;
}

void cutzero(string &now)
{
    int i = 0;
    while (now[i] == '0') i++;
    now = now.substr(i);
}

int flag = 0;
void dfs(string &ans, string s)
{
    queue<string> q;
    q.push(s);

    while (!flag && q.size())
    {
        string &now = q.front();
        if (now.size() <= 3) break;

        auto p = ans.find(now);
        if (p != string::npos)
        {
            flag = 1;
            ans.replace(p, now.size(), "::");
            return;
        }
        q.push(now.substr(1));
        q.push(now.substr(0, now.size() - 1));
        q.pop();
    }
}

int main()
{
    ios::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        string s, mid, ans; cin >> s;
        // Get raw
        for (int i = 0, k = 0; i < (int)s.size(); i += 4, k++)
        {
            if (k && k % 4 == 0) mid += ':';
            string now;
            
            for (int j = 0; j < 4; j++) now += s[i + j];
            mid += toHex(now);
        }

        // cout << mid << "\n";
        // Cut zeros
        // ans = ":";
        for (int i = 0; i < (int)mid.size(); i += 5)
        {
            if (i) ans += ":";
            string now = mid.substr(i, 4);
            cutzero(now);
            if (now.size())
            {
                ans += now;
            }
            else
            {
                ans += "0";
            }
        }
        
        // cout << ans << "\n";
        // Check long 0:
        reverse(ans.begin(), ans.end());
        flag = 0;
        dfs(ans, "0:0:0:0:0:0:0:0");
        reverse(ans.begin(), ans.end());

        // cout << ans << "\n";
        cout << "Case #" << t << ": ";
        if (ans.size() != 2)
        {
            if (ans[0] == ':' && ans[1] != ':')
            {
                ans = ans.substr(1);
            }
            if (ans[ans.size() - 1] == ':' && ans[ans.size() - 2] != ':')
            {
                ans = ans.substr(0, ans.size() - 1);
            }
        }
        cout << ans << "\n";
        
    }

    return 0;
}

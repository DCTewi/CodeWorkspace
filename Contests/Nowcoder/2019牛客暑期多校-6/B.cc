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
        for (int i = 0; i < (int)mid.size(); i += 5)
        {
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
            ans += ":";
        }

        ans = ":" + ans;
        // cout << ans << "\n";
        // Check long 0:
        int maxlen = 0, l = 0, r = 0;
        for (int i = 1; i < ans.size() - 1; i++)
        {
            int nowlen = 0, nowl = i, nowr = i + 1;
            while (ans[i - 1] == ':' && ans[i] == '0' && ans[i + 1] == ':')
            {
                nowlen++; nowr = (i = i + 2);
            }
            if (nowlen >= maxlen)
            {
                maxlen = nowlen;
                l = nowl, r = nowr;
            }
        }
        if (maxlen >= 2)
        {
            // cout << "max0 : " << ans.substr(l, r - l + 1) << "\n";;
            if (l)
            {
                ans.replace(l - 1, r - l + 1, "::");
            }
            else 
            {
                ans.replace(l, r - l + 1, "::");
            }
        }
        // cout << ans << "\n";
        cout << "Case #" << t << ": ";
        if (ans.size() == 2)
        {
            cout << ans << "\n";
        }
        else if (ans[ans.size() - 1] == ':' && ans[ans.size() - 2] != ':')
        {
            cout << ans.substr(1, ans.size() - 2) << "\n";
        }
        else
        {
            cout << ans.substr(1) << "\n";
        }
        
    }

    return 0;
}

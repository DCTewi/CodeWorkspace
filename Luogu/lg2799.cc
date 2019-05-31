#include <bits/stdc++.h>
using namespace std;

int ans;

bool check(string s)
{
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
    {
        if (s[i] != s[j]) return false;
    }
    return true;
}

void solve(string s)
{
    if (s.size() & 1) return;

    if (check(s))
    {
        ans /= 2;
        solve(s.substr(0, s.size() / 2));
    }
}

int main()
{
    string str; cin >> str;

    ans = str.size();

    solve(str);

    cout << ans << "\n";

    return 0;
}
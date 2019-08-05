#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1E6 + 5;

vector<ll> z_function(string s)
{
    ll n = s.size();
    vector<ll> z(n);
    for (ll i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
    {
        string s; cin >> s;
        auto z = z_function(s);
        ll ans = 0, len = s.size();
        for (ll i = 1; i < len; i++)
        {
            ans += (z[len - i] == i)? z[len - i]: z[len - i] + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}


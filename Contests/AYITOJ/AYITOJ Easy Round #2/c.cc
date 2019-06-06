#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const int MAXN = 1e6 + 5;

ll q[MAXN], f[MAXN];

int main()
{
    ios::sync_with_stdio(0);

    ll T, maxt = 0;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> q[i];
        maxt = max(maxt, q[i]);
    }

    f[0] = 1; f[1] = 5;
    for (ll i = 2; i <= maxt; i++)
    {
        f[i] = (f[i - 1] * 5 - f[i - 2] * 2 + MOD * 2) % MOD;
    }

    for (int i = 0; i < T; i++)
    {
        cout << f[q[i]] << "\n";
    }

    return 0;
}

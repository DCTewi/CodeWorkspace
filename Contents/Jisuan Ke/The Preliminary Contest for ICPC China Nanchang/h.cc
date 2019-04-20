#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

ll f[2][2] = {{0, 1}, {2, 4}};

int main()
{
    ios::sync_with_stdio(false);

    ll n; cin>>n;
    if (n == 1) return 0 * puts("1");
    if (n == 2) return 0 * puts("4");

    for (int i = 2; i < n; i++)
    {
        f[0][0] = f[1][0];
        f[0][1] = f[1][1];
        f[1][0] = (f[0][0] + f[0][1]) % MOD;
        f[1][1] = (f[1][0] + f[0][0] + f[0][1]) % MOD;
    }

    cout<<f[1][1]<<"\n";

    return 0;
}
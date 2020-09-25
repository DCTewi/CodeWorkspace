#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 10000000;

ll n;
ll ans = 1;

int main()
{
    ios::sync_with_stdio(0);

    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
        while (ans % 10 == 0 && ans) ans /= 10;
        ans %= MOD;
    }

    cout<<ans % 10<<"\n";

    return 0;
}
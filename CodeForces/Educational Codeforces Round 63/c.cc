#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 5;
ll x[MAXN], p[MAXN];
ll n, m;
map<ll, bool> val;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for (ll i = 1; i <= n; i++)
    {
        cin>>x[i];
    }
    for (ll i = 1; i <= m; i++)
    {
        cin>>p[i];
    }

    ll gcd = x[2] - x[1];
    for (ll i = 2; i < n; i++)
    {
        gcd = __gcd(gcd, x[i + 1] - x[i]);
    }

    for (ll i = 1; i <= (ll)(sqrt(gcd)); i++)
    {
        if (gcd % i == 0)
        {
            val[i] = 1;
            if (gcd / i != i) val[gcd / i] = 1;
        }
    }

    for (ll i = 1; i <= m; i++)
    {
        if (val.count(p[i]))
        {
            cout<<"YES\n"<<x[1]<<" "<<i<<"\n";
            return 0;
        }
    }

    cout<<"NO\n";

    return 0;
}
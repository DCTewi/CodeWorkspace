#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getyins(ll x)
{
    ll res(0);
    for (ll i = 1; i * i <= x; i++)
    {
        if (!(x % i))
        {
            (i * i != x)? res += 2: res++;
        }
    }
    return res;
}

ll read()
{
    ll x = 0; char ch = getchar();
    while (!isdigit(ch))
    {
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}

int main()
{
    ll n =read(), ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll t = read();
        ans = __gcd(ans, t);
    }
    cout << getyins(ans) << endl;
    return 0;
}


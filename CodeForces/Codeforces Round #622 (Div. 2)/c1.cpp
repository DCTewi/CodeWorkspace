#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> T read()
{
    T x = 0; int ch = getchar(), w = 0;
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

const int MAXN = 1e3 + 5;

ll h[MAXN], method[MAXN];

int main()
{
    ll n = read<ll>();

    for (int i = 1; i <= n; i++)
    {
        h[i] = read<ll>(); 
    }

    // if (n == 1)
    // {
    //     return 0 * printf("%d\n", h[1]);
    // }

    ll ans = 0, ansid = 0;
    for (ll i = 1; i <= n; i++)
    {
        //printf("i = %d :\n", i);
        ll now = h[i], heightnow = h[i];
        for (ll j = i - 1; j > 0; j--)
        {
            heightnow = min(heightnow, h[j]);
            now += heightnow;
            //printf("\tj = %d, hnow = %d, now = %d\n", j,heightnow, now);
        }
        heightnow = h[i];
        for (ll j = i + 1; j <= n; j++)
        {
            heightnow = min(heightnow, h[j]);
            now += heightnow;
            //printf("\tj = %d, hnow = %d, now = %d\n", j,heightnow, now);
        }
        if (now > ans)
        {
            ans = now; ansid = i;
        }
    }

    method[ansid] = h[ansid];
    for (ll j = ansid - 1; j > 0; j--)
    {
        method[j] = min(method[j + 1], h[j]);

    }
    for (ll j = ansid + 1; j <= n; j++)
    {
        method[j] = min(method[j - 1], h[j]);
    }

    for (ll i = 1; i <= n; i++)
    {
        printf("%lld%c", method[i], " \n"[i == n]);
    }

    return 0;
}
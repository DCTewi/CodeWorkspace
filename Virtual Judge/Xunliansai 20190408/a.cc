#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

bool check(ll x)
{
    ll a = 0, b = 0;
    bool fir = true;
    auto flag = x & 1;
    while (x)
    {
        ll na = 0, nb = 0;
        while (x && (x & 1) == flag)
        {
            x >>= 1; na++;
        }
        while (x && (x & 1) != flag)
        {
            x >>= 1; nb++;
        }
        
        if (fir)
        {
            a = na; b = nb;
            fir = 0;
        }
        else
        {
            if ((a != na || b != nb) && !(a == na && !nb && !x))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cout<<(1ULL << 63) - 1<<endl;
    ll l, r; cin>>l>>r;
    ll ans = 0;
    for (ll i = l; i <= r; i++)
    {
        if (check(i))
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

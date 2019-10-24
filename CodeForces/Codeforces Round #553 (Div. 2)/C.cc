#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

ll l, r;
ll nodd = 0, neven = 0;

void get_num(ll l, ll r)
{
    ll len = 1, now = 1;
    while (r)
    {
        if (r & 1)
        {
            if (len & 1)
            {
                nodd = (nodd + now) % MOD;
            }
            else
            {
                neven = (neven + now) % MOD;
            }
        }
        len++;
        now <<= 1;
        r >>= 1;
    }
    len = 1, now = 1;
    while (l)
    {
        if (l & 1)
        {
            if (len & 1)
            {
                nodd = (nodd - now) % MOD;
            }
            else
            {
                neven = (neven - now) % MOD;
            }
        }
        len++;
        now <<= 1;
        l >>= 1;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>l>>r;

    get_num(l, r);

    cout<<nodd<<" "<<neven<<endl;

    ll ans = 0;

    ans = ans + ((nodd) % MOD + (nodd) % MOD) % MOD;

    ans = ans + ((neven * 2LL) % MOD + (neven * (neven - 1)) % MOD) % MOD;

    cout<<ans<<"\n";

    return 0;
}
// 1 2 4 8 16....
// 2

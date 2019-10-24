#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll rev(ll p)
{
    ll res = 0;
    while (p)
    {
        res = res * 10 + p % 10; p /= 10;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
    {
        ll a, b, x = 0, y = 0;
        cin >> a >> b;
        cout << rev(rev(a) + rev(b)) << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x)
{
    x += 1;
    while (!(x % 10))
    {
        x /= 10;
    }
    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    ll n; cin >> n;

    ll ans = 0, x = n;
    set<int> s;

    while (!s.count(x))
    {
        s.insert(x);
        x = f(x);
    }

    cout<<s.size()<<"\n";
    return 0;
}
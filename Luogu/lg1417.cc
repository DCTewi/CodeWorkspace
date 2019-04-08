#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
ll t, n;

struct Food
{
    ll a, b, c;

    Food(ll a = 0, ll b = 0, ll c = 0)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    bool operator< (const Food &o) const
    {
        return this->c * o.b < o.c * this->b;
    }
}food[MAXN];

ll f[MAXN], ans = -999999;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t>>n;
    for (int i = 1; i <= n; i++) cin>>food[i].a;
    for (int i = 1; i <= n; i++) cin>>food[i].b;
    for (int i = 1; i <= n; i++) cin>>food[i].c;

    sort(food + 1, food + n + 1, [](Food a, Food b)->bool{return a < b;});

    for (int i = 1; i <= n; i++)
    {
        for (int j = t; j >= 0; j--)
        {
            if (j >= food[i].c)
            {
                f[j] = max(f[j], f[j - food[i].c] + food[i].a - j * food[i].b);
                ans = max(ans, f[j]);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}

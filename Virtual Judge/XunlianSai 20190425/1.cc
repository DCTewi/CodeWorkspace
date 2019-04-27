// k
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
const int MAXN = 1e2 + 5;
ll a[MAXN], ans[MAXN];
int n, k;

ll getk(int x)
{
    ll res = 1;
    for (int i = 1; i <= k && x >= 0; i++, x--)
    {
        res = res * x % MOD;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = n; i >= 0; i--)
    {
        cin>>a[i];
    }
    for (int i = 0; i < k; i++)
    {
        cout << "0 ";
    }
    for (int i = n; i >= k; i--)
    {
        //ans[i] = a[i] * getk(i);
        cout<<a[i] * getk(i) % MOD<<" ";
    }

    return 0;
}
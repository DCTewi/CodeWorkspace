#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sg(int x, int y)
{
    ll res = 2;
    for (int i = 0; ; i++, res <<= 1)
    {
        if ((x - 1) % res < res >> 1 && (y - 1) % res < res >> 1)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--)
    {
        int n, ans = 0; cin >> n;
        for (int i = 0; i < n / 2; i++)
        {
            int x, y; cin >> x >> y;
            ans ^= sg(x, y);
        }
        cout<<(ans? "YES\n": "NO\n");
    }

    return 0;
}
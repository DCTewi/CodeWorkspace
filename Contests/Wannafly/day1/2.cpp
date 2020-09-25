#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

int n, m, k;
ll a[MAXN], b[MAXN];

ll getcnt(ll v)
{
    int i = 0, j = m - 1;
    ll cnt = 0;
    while (i < n && j >= 0)
    {
        if (a[i] * b[j] > v)
        {
            cnt += n - i; j--;
        }
        else
        {
            i++;
        }
    }
    return cnt;
}

ll solve(ll l, ll r, ll cnt)
{
    if (l == r) return l;
    ll mid = (l + r) >> 1;

    if (getcnt(mid) >= cnt)
    {
        return solve(mid + 1, r, cnt);
    }
    if (getcnt(mid - 1) < cnt)
    {
        return solve(l, mid - 1, cnt);
    }
    return mid;
}

ll kth(ll k)
{
    ll r = a[n - 1] * b[m - 1], l = a[0] * b[0];
    return solve(l, r, k);
}

int main()
{
    n = read<int>(), m = read<int>(), k = read<int>();

    for (int i = 0; i < n; i++) a[i] = read<ll>();
    for (int i = 0; i < m; i++) b[i] = read<ll>();

    sort(a, a + n);
    sort(b, b + m);

    printf("%lld\n", kth(k));

    return 0;
}

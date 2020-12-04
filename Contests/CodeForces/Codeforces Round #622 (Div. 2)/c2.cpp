#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MAXN = 500005;
LL h[MAXN], n;
LL ls[MAXN], rs[MAXN];
LL l[MAXN], r[MAXN];
LL ans[MAXN];
stack<LL> s;
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (LL i = 1; i <= n; ++i)
        cin >> h[i];

    for (LL i = 1; i <= n; ++i)
    {
        while (!s.empty() && h[s.top()] >= h[i])
            s.pop();
        if (s.empty())
            l[i] = 0;
        else
            l[i] = s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (LL i = n; i; --i)
    {
        while (!s.empty() && h[s.top()] >= h[i])
            s.pop();
        if (s.empty())
            r[i] = n + 1;
        else
            r[i] = s.top();
        s.push(i);
    }
    l[0] = -1, r[n + 1] = n + 2;

    for (LL i = 1; i <= n; ++i)
        ls[i] = ls[l[i]] + (i - l[i]) * h[i];
    for (LL i = n; i; --i)
        rs[i] = rs[r[i]] + (r[i] - i) * h[i];

    LL maxi = 0, maxv = -1;
    for (LL i = 1; i <= n; ++i)
        if (ls[i] + rs[i] - h[i] > maxv)
            maxi = i, maxv = ls[i] + rs[i] - h[i];

    for (LL i = maxi; i >= 0; i = l[i])
        for (LL j = i; j > l[i]; --j)
            ans[j] = h[i];
    for (LL i = maxi; i <= n + 1; i = r[i])
        for (LL j = i; j < r[i]; ++j)
            ans[j] = h[i];
    for (LL i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    return 0;
}

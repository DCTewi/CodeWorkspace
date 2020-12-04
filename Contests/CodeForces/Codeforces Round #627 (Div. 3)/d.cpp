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

const int MAXN = 2e4 + 5;
int a[MAXN], b[MAXN];

int main()
{
    int n = read<int>();
    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        a[i] = read<int>();
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = read<int>();
        a[i] -= b[i];
    }

    vector<int> v1, v2;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 0) v1.emplace_back(a[i]);
        else v2.emplace_back(a[i]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    ans += (1ll * v1.size() * v1.size() - v1.size()) >> 1;
    int now = v1.size();
    for (int p : v2)
    {
        while (now && v1[now - 1] + p > 0)
        {
            now --;
        }
        ans += v1.size() - now;
    }

    printf("%lld\n", ans);

    return 0;
}

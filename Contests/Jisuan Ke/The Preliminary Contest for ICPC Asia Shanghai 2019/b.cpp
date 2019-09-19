#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
int v[MAXN], n, m;

template <typename T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

inline void add(int &l, int &r)
{
    v[l]++; v[r + 1]--;
}

int main()
{
    int _T = read<int>();
    for (int T = 1; T <= _T; T++)
    {
        memset(v, 0, sizeof(v));
        n = read<int>(), m = read<int>();
        for (int i = 1; i <= m; i++)
        {
            int l = read<int>(), r = read<int>();
            add(l, r);
        }

        int now = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            now += v[i];
            if (now & 1) ans++;
        }

        printf("Case #%d: %d\n", T, ans);
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

int main()
{
    int T = read<int>();
    while (T--)
    {
        int n = read<int>(), m = read<int>(), k = read<int>(), ans = -(1 << 30);
        k = min(k, m - 1);
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = read<int>();
        }
        for (int i = 0; i <= k;i++)
        {
            int u = 1 << 30;
            for (int j = 0; j < m - k; j++)
            {
                u = min(u, max(a[i + j], a[n + i + j - m]));
            }
            ans = max(ans, u);
        }

        printf("%d\n", ans);
    }
    return 0;
}

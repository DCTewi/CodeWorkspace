#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int ch = getchar(), w = 0;
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

const int MAXN = 3e4 + 5;

int n, m;
int f[MAXN], w[MAXN], v[MAXN];

int main()
{
    int T = read<int>();
    for (int _T = 1; _T <= T; _T++)
    {
        memset(f, 0, sizeof f);
        int m = read<int>(), n = read<int>();
        for (int i = 1; i <= n; i++)
        {
            w[i] = read<int>();
        }
        for (int i = 1; i <= n; i++)
        {
            v[i] = read<int>();
        }

        for(int i = 1; i <= n; i++)
        {
            for(int c = m; c >= 0; c--)
            {
                if(c >= w[i])
                f[c] = max(f[c], f[c - w[i]] + v[i]);
            }
        }

        printf("Case #%d: %d\n", _T, f[m]);
    }
    return 0;
}
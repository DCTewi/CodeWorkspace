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

const int MAXN = 5e2 + 5;
int f[MAXN][MAXN], a[MAXN][MAXN];

int main()
{
    int n = read<int>();
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
        }
    }

    printf("%d\n", f[n][n]);

    return 0;
}
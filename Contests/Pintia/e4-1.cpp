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

const int MAXN = 1e2 + 5;

int a[MAXN][MAXN], dp[MAXN][MAXN];

int main()
{
    int n = read<int>();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            a[i][j] = read<int>();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp[n][i] = a[n][i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
        }
    }
    printf("%d\n", dp[1][1]);

    return 0;
}

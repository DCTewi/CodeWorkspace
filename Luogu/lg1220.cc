#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e2 + 5;

int n, c;
int p[MAXN], sum[MAXN];
int f[MAXN][MAXN][2]; // 0 = left, 1 = right;

inline int get_sum(int l, int r)
{
    // [1, l] + [r, n] 
    return sum[l] + sum[n] - sum[r - 1];
}

int main()
{
#ifndef DEBUG
    ios::sync_with_stdio(0);
#endif
    memset(f, 0x3f, sizeof(f));

    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i] >> sum[i];
        sum[i] += sum[i - 1];
    }

    f[c][c][0] = f[c][c][1] = 0;

    for (int len = 2; len <= n; len++) // length
    {
        for (int i = 1; i + len - 1 <= n; i++) // l
        {
            int j = i + len - 1; // r

            f[i][j][0] = min
            (
                f[i + 1][j][0] + (p[i + 1] - p[i]) * get_sum(i, j + 1), // i + 1 => i
                f[i + 1][j][1] + (p[j] - p[i]) * get_sum(i, j + 1) // j => i
            );
            f[i][j][1] = min
            (
                f[i][j - 1][0] + (p[j] - p[i]) * get_sum(i - 1, j), // i => j
                f[i][j - 1][1] + (p[j] - p[j - 1]) * get_sum(i - 1, j) // j - 1 => i
            );
        }
    }

    cout << min(f[1][n][0], f[1][n][1]) << "\n";

    return 0;
}
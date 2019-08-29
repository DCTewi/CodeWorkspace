#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 5;
const int LOGN = 25;

ll f[MAXN][LOGN], logn[MAXN + 1];
int n, k;

inline int read()
{
    int x = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

void pre()
{
    logn[1] = 0;
    logn[2] = 1;
    for (int i = 3; i <= MAXN; i++)
    {
        logn[i] = logn[i / 2] + 1;
    }
}

int query(int x, int y)
{
    int s = logn[y - x + 1];
    return max(f[x][s], f[y - (1 << s) + 1][s]);
}

int main()
{
    int T = read(); pre();
    while (T--)
    {
        memset(f, 0, sizeof(f));
        n = read(), k = read();
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            f[i][0] = read();
        }
        for (int j = 1; j <= LOGN; j++)
        {
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
            {
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }

        for (int l = 1; l <= n; l++)
        {
            map<int, int> num;
            for (int len = 0; l + len <= n; len++)
            {
                if (num.count(f[l + len][0])) break;
                num[f[l + len][0]]++;
                if (query(l, l + len) - len - 1 <= k) ans++;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}


#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <deque>
#include <bitset>
using namespace std;
typedef long long ll;

template<class T> T read()
{
    T x = 0; int ch = getchar(), w = 0;
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

const int MAXN = 2e2 + 5;

int m, n;
int a[MAXN][MAXN];
int opt[MAXN][MAXN], ans[MAXN][MAXN];
int anscnt = 1 << 30;

const int dx[] = {-1, 1, 0, 0, 0};
const int dy[] = {0, 0, 0, 1, -1};

int get_color(int x, int y)
{
    int color = a[x][y];
    for (int i = 0; i < 5; i++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m)
        {
            color += opt[tx][ty];
        }
    }
    return color % 2;
}

int get_count()
{
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (get_color(i - 1, j))
            {
                opt[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (get_color(n - 1, i)) return 1 << 30;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cnt += opt[i][j];
        }
    }
    return cnt;
}

int main()
{
    n = read<int>(), m = read<int>();

    for (int i = 0; i < n; i++)
    {
        for  (int j = 0; j < m; j++)
        {
            a[i][j] = read<int>();
        }
    }

    for (int i = 0; i < (1 << m); i++)
    {
        memset(opt, 0, sizeof(opt));
        for(int j = 0; j < m; j++)
        {
            opt[0][j] = i >> (n - j - 1) & 1;
        }
        int cnt = get_count();

        if (cnt < anscnt)
        {
            anscnt = cnt;
            memcpy(ans, opt, sizeof(opt));
        }
    }

    if (anscnt == (1 << 30))
    {
        puts("IMPOSSIBLE");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d%c", ans[i][j], " \n"[j == m - 1]);
            }
        }
    }

    return 0;
}

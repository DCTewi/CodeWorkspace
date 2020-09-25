#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

const int MAXN = 1e2 + 5;
const int INF = 1 << 30;
int n, m;
int sx = -1, sy = -1;
int tile[MAXN][MAXN], ans[MAXN][MAXN];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int rx[] = {-1, 0, 0, 1, 1, 0, 0, -1};
int ry[] = {0, 1, 1, 0, 0, -1, -1, 0};

int main()
{
    n = read<int>(), m = read<int>();
    for (int i = 1; i <= n; i++)
    {
        string tmp; cin >> tmp;
        for (int j = 1; j <= m; j++)
        {
            ans[i][j] = INF;
            if (tmp[j - 1] == 'M')
            {
                sx = i, sy = j;
            }
            else if (tmp[j - 1] == 'X')
            {
                tile[i][j] = 1;
            }
        }
    }

    ans[sx][sy] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    while (q.size())
    {
        int x = q.front().first, y = q.front().second;
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || nx > n|| ny <= 0 || ny > m) continue;
            if (tile[x + rx[i]][y + ry[i]] || tile[nx][ny]) continue;
            if (ans[nx][ny] != INF) continue;

            ans[nx][ny] = ans[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
        q.pop();
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ans[i][j] == INF) printf("-1");
            else printf("%d", ans[i][j]);
            if (j < m) printf(" ");
        }
        if (i < n) printf("\n");
    }

    return 0;
}
/**
6 6
...M..
...X..
......
......
......
......

*/
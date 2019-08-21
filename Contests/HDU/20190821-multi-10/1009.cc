#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e3 + 5;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int n, m, q;
int a[MAXN][MAXN], vis[MAXN][MAXN];

int read()
{
    int x = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

bool check(const int &x, const int &y)
{
    int resl = 0, rest = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (a[nx][ny]) (i < 2)? rest++: resl++;
    }
    return resl && rest;
}

void update(int x, int y)
{
    int cnt = 0;
    if (a[x][y])
    {
        puts("0"); return;
    }

    a[x][y] = 1; cnt++;
    queue<pair<int, int>> q;
    vis[x][y] = 1; q.push(make_pair(x, y));
    while (q.size())
    {
        auto u = q.front();
        int ux = u.first, uy = u.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = ux + dx[i], ny = uy + dy[i];
            if (!vis[nx][ny] && !a[nx][ny] && check(nx, ny))
            {
                cnt++; q.push(make_pair(nx, ny)); vis[nx][ny] = 1; a[nx][ny] = 1;
            }
        }
        q.pop(); vis[ux][uy] = 0;
    }
    printf("%d\n", cnt);
}

int main()
{
    //freopen("input", "r", stdin);
    int T = read();
    while (T--)
    {
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));

        n = read(), m = read(), q = read();
        for (int i = 0; i < q; i++)
        {
            update(read(), read());
        }
    }
    return 0;
}


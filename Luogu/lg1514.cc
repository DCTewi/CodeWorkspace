#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e2 + 5;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int tile[MAXN][MAXN];
int vis[MAXN][MAXN];
int n, m;
int ans = 0, leave = 0;

struct Node
{
    int x, y;

    Node(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
};

map<Node, bool> picked;

bool getPath(int p)
{
    memset(vis, 0, sizeof(vis));

    queue<Node> q;
    q.push(Node(p, m));
    vis[p][m] = 1;

    while (q.size())
    {
        Node u = q.front();
        bool flag = false;
        for (int i = 0; i < 4; i++)
        {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            if ((!vis[nx][ny]) && tile[nx][ny] > tile[u.x][u,y])
            {
                flag = true;
                q.push(Node(nx, ny));
            }
        }
        if (!flag && u.y == 1)
        {

        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    leave = m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>tile[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        if (!getPath(i))
        {
            puts("0");
            cout<<left<<endl;
        }
    }

    if (left == 0)
    {
        puts("1");
        cout<<ans<<endl;
    }
    else
    {
        puts("0");
        cout<<leave<<endl;
    }


    return 0;
}

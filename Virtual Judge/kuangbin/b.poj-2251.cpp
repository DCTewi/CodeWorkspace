#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 35;
const int dl[] = {1, -1, 0, 0, 0, 0};
const int dr[] = {0, 0, 1, -1, 0, 0};
const int dc[] = {0, 0, 0, 0, 1, -1};

int l, r, c;
size_t tmp;
string tile[MAXN][MAXN];
struct Node
{
    int l, r, c;
    
}s, e;

int dis[MAXN][MAXN][MAXN];
int bfs()
{
    queue<Node> q;
    q.push(s); dis[s.l][s.r][s.c] = 0;
    while (q.size())
    {
        Node p = q.front();

        for (int i = 0; i < 6; i++)
        {
            int nx = p.l + dl[i], ny = p.r + dr[i], nz = p.c + dc[i];
            if (nx >= l || ny >= r || nz >= c || nx < 0 || ny < 0 || nz < 0) continue;
            if (dis[nx][ny][nz] == 0x3f3f3f3f && tile[nx][ny][nz] != '#')
            {
                q.push((Node){nx, ny, nz});
                dis[nx][ny][nz] = dis[p.l][p.r][p.c] + 1;
            }
        }
        q.pop();
    }
    return dis[e.l][e.r][e.c];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    while (cin >> l >> r >> c)
    {
        if (!(l || r || c)) return 0;
        memset(dis, 0x3f, sizeof(dis));
        s = e = (Node){-1, -1, -1};

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                cin >> tile[i][j];
                if (!~(s.l) && ((tmp = tile[i][j].find_first_of('S')) != string::npos))
                {
                    s = (Node){i, j, (int)tmp};
                }
                if (!~(e.l) && ((tmp = tile[i][j].find_first_of('E')) != string::npos))
                {
                    e = (Node){i, j, (int)tmp};
                }
            }
        }

        if (bfs() == 0x3f3f3f3f) cout << "Trapped!\n";
        else cout << "Escaped in " << dis[e.l][e.r][e.c] << " minute(s).\n";
    }
    return 0;
}

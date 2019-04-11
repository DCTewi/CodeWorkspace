//G
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;
int n, m;
struct Edge
{
    int x1, x2, y1, y2;

    Edge (int a = 0, int b = 0, int x = 0, int y = 0)
    {
        this->x1 = a; this->y1 = b; this->x2 = x; this->y2 = y;
    }
}edge[MAXN];

bool cross(Edge a, Edge b)
{
    int x = (b.x1 - a.x1) * (a.y2 - a.y1) - (b.y1 - a.y1) * (a.x2 - a.x1);
    int y = (b.x2 - a.x1) * (a.y2 - a.y1) - (b.y2 - a.y1) * (a.x2 - a.x1);

    return x + y;
}

bool pal(Edge a, Edge b)
{
    int xx1 = a.x2 - a.x1;
    int yy1 = a.y2 - a.y1;
    int xx2 = b.x2 - b.x1;
    int yy2 = b.y2 - b.y1;

    return xx1 * yy2 == xx2 * yy1;
}

int cnt = 0, ans = 0;
int allpal = 1;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    
    for (int i = 0; i < m; i++)
    {
        int m, n, p, q;
        cin>>m>>n>>p>>q;
        Edge now = Edge(m, n, p, q);
        
        if (!cnt)
        {
            edge[cnt++] = now;
        }
        else
        {
            int flag = 0;
            for (int i = 0; i < cnt; i++)
            {
                if (!cross(now, edge[i]))
                {
                    flag = 1; break;
                }
                if (!pal(now, edge[i])) allpal = 0;
            }
            if (!flag) edge[cnt++] = now;
        }
    }
    
    if (allpal) ans = cnt + 1;
    else ans = cnt * 2;
    
    if (ans >= n) return 0 * puts("0");
    
    else if (allpal)
    {
        if (ans * 2 >= n) puts("1");
        else cout<<(n - ans * 2 - 1) / 2 + 1 + 1;
    }
    else 
    {
        cout<<(n - ans - 1) / 2 + 1;
    }
    
    return 0;
}

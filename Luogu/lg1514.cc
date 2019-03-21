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

map<int, bool> picked;

bool getPath(int p)
{
    memset(vis, 0, sizeof(vis));

    queue<Node> q;
    q.push(Node(n, p));
    vis[p][n] = 1;

    while (q.size())
    {
        Node u = q.front();
        //cout<<"now is "<<u.x<<" "<<u.y<<endl;
        bool flag = false;
        for (int i = 0; i < 4; i++)
        {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            if (nx > 0 && nx <= n && ny > 0 && ny <= m)
            {
            	//cout<<"\ttry going to "<<nx<<","<<ny<<endl;
            if ((!vis[nx][ny]) && tile[nx][ny] > tile[u.x][u.y])
            {
            	//cout<<"\t\twent to"<<nx<<","<<ny<<endl;
                flag = true;
                q.push(Node(nx, ny));
                //cout<<u.x<<" "<<u.y<<"("<<tile[u.x][u.y]<<") -> "<<nx<<" "<<ny<<"("<<tile[nx][ny]<<")"<<endl;
            }
        	}
        }
        if (!flag && u.x == 1)
        {
            leave--;
            if (picked.count(u.y) == 0)
            {
            	picked[u.y] = true;
            	ans++;
            }
            //cout<<"=====\t\t\t\tpicked "<<u.x<<endl;
            return true;
        }
        //cout<<"back"<<endl;
        q.pop();
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    leave = m;
    for (int i = 1; i <= n; i++)
    {
        //cout<<i<<":"<<endl;
        for (int j = 1; j <= m; j++)
        {
            //cout<<j<<": ";
            cin>>tile[i][j];
        }
    }
/*
    for (int i = 1; i <= n; i++)
    {
    	for (int j = 1; j <= m; j++)
    	{
    		cout<<i<<","<<j<<":"<<tile[i][j]<<" , ";
    	}
    	cout<<endl;
    }
*/
    for (int i = 1; i <= m; i++)
    {
        if (!getPath(i))
        {
        	puts("0");
        	cout<<leave<<endl;
        	return 0;
        }
    }

    if (leave == 0)
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

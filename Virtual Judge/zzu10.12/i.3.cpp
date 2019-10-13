#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e2 + 5;
const int INF = 0xfffFFFF;

int n;
string nameof[MAXN];
map<string, int> id;

int edge[MAXN][MAXN], dis[MAXN][MAXN], pre[MAXN][MAXN];
int ans = INF;

void addedge(int u, int v)
{
    edge[u][v] = dis[u][v] = 1;

    if (u == v && ans == INF)
    {
        ans = u;
    }
}

void init()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            edge[i][j] = dis[i][j] = INF;
        }
    }
}

void print_path(int i, int j)
{
    if (i == j) return;
    if (!pre[i][j]) cout << nameof[j] << " ";
    else
    {
        print_path(i, pre[i][j]);
        print_path(pre[i][j], j);
    }
}

void floyd()
{
    int x = 0, y = 0, z = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][j] != INF && edge[k][i] != INF && edge[j][k] != INF)
                {
                    if (ans > dis[i][j] + edge[k][i] + edge[j][k])
                    {
                        ans = dis[i][j] + edge[k][i] + edge[j][k];
                        x = i, y = j, z = k;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] != INF && dis[k][j] != INF)
                {
                    if (dis[i][j] > dis[i][k] + dis[k][j])
                    {
                        dis[i][j] = dis[i][k] + dis[k][j];
                        pre[i][j] = k;
                    }
                }
            }
        }
    }

    if (ans == INF) cout << "SHIP IT\n";
    else
    {
        cout << nameof[x] << " ";
        print_path(x, y);
        cout << nameof[z] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    init();
    for (int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        nameof[i] = s;
        id[s] = i;
    }

    for (int i = 0; i < n; i++)
    {
        string s; int lines = 0;
        cin >> s >> lines;
        for (int j = 0; j < lines; j++)
        {
            string now; cin >> now;
            do
            {
                cin >> now;
                addedge(id[s], id[now.substr(0, now.size() - (now[now.size() - 1] == ','))]);
            }
            while (now[now.size() - 1] == ',');
        }
    }

    if (ans != INF)
    {
        cout << nameof[ans] << "\n";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (edge[i][j] == 1 && edge[j][i] == 1)
            {
                cout << nameof[i] << " " << nameof[j] << "\n";
                return 0;
            }
        }
    }

    floyd();

    return 0;

}


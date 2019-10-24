#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e2 + 5;
const int INF = 0xfffFFFF;

int n;
string nameof[MAXN];
map<string, int> id;

int edge[MAXN][MAXN], dis[MAXN][MAXN], pre[MAXN][MAXN], path[MAXN];
int ans = INF;

void addedge(int u, int v)
{
    edge[u][v] = dis[u][v] = 1;
    //cout << "Linked " << u << " -> " << v << "\n"; 

    if (u == v && ans == INF)
    {
        ans = u;
    }
}

void init()
{
    memset(pre, 0, sizeof(pre));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            edge[i][j] = dis[i][j] = INF;
        }
    }
}

void printpath(int l, int r)
{
    if (l == r) return;
    if (!pre[l][r]) cout << " " << nameof[r];
    else
    {
        printpath(l, pre[l][r]);
        printpath(pre[l][r], r);
    }
}

void floyd()
{
    int l = 0, mid = 0, r = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i == j) continue;
                if (dis[i][j] != INF && edge[k][i] != INF && edge[j][k] != INF && ans > dis[i][j] + edge[k][i] + edge[j][k])
                {
                    ans = dis[i][j] + edge[k][i] + edge[j][k];
                    l = i, mid = j, r = k;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == k || j == k) continue;
                if (dis[k][j] != INF && dis[i][k] != INF && dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    pre[i][j] = k;
                }
            }
        }
    }


    if (ans == INF) cout << "SHIP IT\n";
    else
    {
        cout << nameof[l];
        printpath(l, mid);
        cout << " " << nameof[r] << "\n";
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
                addedge(id[now.substr(0, now.size() - (now[now.size() - 1] == ','))], id[s]);
            }
            while (now[now.size() - 1] == ',');
        }
    }

    if (ans != INF)
    {
        cout << nameof[ans] << "\n";
        return 0;
    }

    floyd();

    return 0;

}

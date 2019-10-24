#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e2 + 5;
const int INF = 0xfffFFFF;

int n;
string nameof[MAXN];
map<string, int> id;

int ans = INF;

struct Edge
{
    int to = 0, next = 0;
} edge[MAXN << 2] ;
int head[MAXN];
void addedge(int u, int v)
{
    if (u == v && ans == INF)
    {
        ans = u;
        return;
    }

    static int cnt = 0;
    cnt++;
    edge[cnt] = Edge{v, head[u]};
    head[u] = cnt;
}

void bfs(int s)
{

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


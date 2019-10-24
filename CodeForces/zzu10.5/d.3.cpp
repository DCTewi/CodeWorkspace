#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

const int MAXN = 1e5 + 5;

int n, k;

struct Edge
{
    int to, next;
} edges[MAXN << 2];
int head[MAXN];
inline void addedge(int u, int v)
{
    static int cnt = 0;
    cnt++;
    edges[cnt] = {v, head[u]};
    head[u] = cnt;
}
vector<int> allson[MAXN];

int len[MAXN], son[MAXN];
void niubi(int u, int f)
{
    for (int i = head[u]; i; i = edges[i].next)
    {
        int &v = edges[i].to;
        if (v != f)
        {
            niubi(v, u);
            if (len[v] > len[son[u]]) son[u] = v;
        }
    }
    len[u] = len[son[u]] + 1;
}

struct Node
{
    int id, len;
    bool operator< (const Node &o) const
    {
        return len < o.len;
    }
};

int main()
{
    n = read<int>(), k = read<int>();

    for (int i = 2; i <= n; i++)
    {
        int v = read<int>();
        addedge(i, v);
        addedge(v, i);
        allson[v].emplace_back(i);
    }

    niubi(1, 0);

    int ans = 0;
    priority_queue<Node> q;
    q.push({1, len[1]});
    for (int t = 1; t <= k && q.size(); t++)
    {
        auto now = q.top();q.pop();
        ans += now.len;

        int p = now.id;
        while (son[p])
        {
            for (auto i : allson[p])
            {
                if (i != son[p])
                {
                    q.push({i, len[i]});
                }
            }
            p = son[p];
        }
    }
    printf("%d\n", ans);

    return 0;
}

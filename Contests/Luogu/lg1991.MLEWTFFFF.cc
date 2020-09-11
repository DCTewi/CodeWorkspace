#include <bits/stdc++.h>
using namespace std;
using Edge = tuple<double, int, int>;

constexpr int MAXN = 505;

int s, p;
double ans = 0.0;
int fa[MAXN], x[MAXN], y[MAXN];
vector<Edge> edge;

inline double get_dis(int u, int v)
{
    return sqrt
    (
        (x[u] - x[v]) * (x[u] - x[v]) + 
        (y[u] - y[v]) * (y[u] - y[u])
    );
}

inline int getfa(int u)
{
    return fa[u] == u? u: fa[u] = getfa(u);
}

int main()
{
    ios::sync_with_stdio(0);

    cin >> s >> p;
    for (int i = 1; i <= p; i++)
    {
        cin >> x[i] >> y[i];
        for (int j = 1; j < i; j++)
        {
            edge.emplace_back(Edge(i, j, get_dis(i, j)));
        }
    }

    for (int i = 1; i <= p; i++)
    {
        fa[i] = i;
    }

    sort(edge.begin(), edge.end());

    int cnt = 0, len = edge.size();
    for (auto &e : edge)
    {
        if (getfa(get<1>(e)) != getfa(get<2>(e)))
        {
            cnt--;
        }
        if (cnt >= p - s)
        {
            cout << fixed << setprecision(2) << get<0>(e) << "\n";
            return 0;
        }
    }

    return 0;
}

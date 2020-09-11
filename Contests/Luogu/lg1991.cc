#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 5e2 + 5;

using Edge = tuple<double, int, int>;
using Node = pair<int, int>;

int s, p;
int f[MAXN];
vector<Edge> edge;
Node pos[MAXN];

constexpr double get_dis(Node a, Node b)
{
    return sqrt
    (
        (a.first - b.first) * (a.first - b.first) + 
        (a.second - b.second) * (a.second - b.second)
    );
}

inline int getf(int u)
{
    return f[u] == u? u: f[u] = getf(f[u]);
}

inline void unit(int u, int v)
{
    f[getf(u)] = getf(v);
}

int main()
{
    ios::sync_with_stdio(0);

    cin >> s >> p;
    for (int i = 1; i <= p; i++)
    {
        cin >> pos[i].first >> pos[i].second;
        for (int j = 1; j < i; j++)
        {
            edge.emplace_back(make_tuple(get_dis(pos[i], pos[j]), i, j));
        }
    }

    iota(f + 1, f + 1 + p, 1);
    sort(edge.begin(), edge.end());

    int cnt = p - s;
    for (auto &e : edge)
    {
        int u = get<1>(e), v = get<2>(e);
        if (getf(u) != getf(v))
        {
            unit(u, v);
            cnt--;
        }
        if (!cnt)
        {
            cout << fixed << setprecision(2) << get<0>(e) << "\n";
            return 0;
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

template <class T> T read()
{
    T x = 0;
    int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while ( isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

int n;

typedef pair<int, int> Node;
typedef pair<int, int> Index;
typedef pair<int, int> Edge;

vector<Node> nodes;
map<Edge, vector<Index>> m;

Edge make_edge(const Node &a, const Node &b)
{
    int x = abs(a.first - b.first);
    int y = abs(a.second - b.second);
    if (x > y) swap(x, y);

    return make_pair(x, y);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, y; scanf("%d%d", &x, &y);
        nodes.emplace_back(make_pair(x, y));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            m[make_edge(nodes[i], nodes[j])].emplace_back(make_pair(i, j));
        }
    }

    for (auto p : m)
    {
        cout << p.first.first << ", " << p.first.second << "\n";
        for (auto x : p.second)
        {
            cout << "\t" << x.first + 1 << " - " << x.second + 1 << "\n";
        }
    }
    return 0;
}

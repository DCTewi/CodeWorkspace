#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

const int MAXN = 5e5 + 5;
int n, k;
set<int> wish;

struct Edge
{
    int to, cost, next;
    Edge(int to = 0, int cost = 0, int next = 0) : to(to), cost(cost), next(next) {}
} edges [MAXN << 2];
int head[MAXN];
void addedge(int u, int v, int w)
{
    static int cnt = 0;
    cnt++;
    edges[cnt] = Edge(v, w, head[u]);
    head[u] = cnt;
}

int main()
{
    n = read<int>(), k = read<int>();
    for (int i = 1; i < n; i++)
    {
        int u = read<int>(), v = read<int>(), w = read<int>();
        addedge(u, v, w);
        addedge(v, u, w);
    }
    for (int i = 0; i < k; i++)
    {
        int p = read<int>();
        wish.insert(p);
    }

    return 0;
}
/**
6 2
1 2 1
2 3 2
2 5 3
3 4 4
3 6 5
5
6

*/
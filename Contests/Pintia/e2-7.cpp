#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> T read()
{
    T x = 0; int ch = getchar(), w = 0;
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

const int MAXN = 1e4 + 5;

int n;
struct Node
{
    int x, y;
} node[MAXN];
ll ans = 0;

int main()
{
    n = read<int>();
    for (int i = 1; i <= n; i++)
    {
        node[i].x = read<int>();
        node[i].y = read<int>();
    }
    sort(node + 1, node + 1 + n, [](const Node &a, const Node &b)
    {
        return a.y < b.y;
    });
    int midy = node[(n + 1) / 2].y;

    for (int i = 1; i <= n; i++)
    {
        ans += abs(node[i].y - midy);
    }
    sort(node + 1, node + 1 + n, [](const Node &a, const Node &b)
    {
        return a.x < b.x;
    });

    for (int i = 1; i <= n; i++)
    {
        node[i].x -= i;
    }
    sort(node + 1, node + 1 + n, [](const Node &a, const Node &b)
    {
        return a.x < b.x;
    });

    int midx = node[(n + 1) / 2].x;
    for (int i = 1; i <= n; i++)
    {
        ans += abs(node[i].x - midx);
    }

    printf("%lld\n", ans);
    return 0;
}
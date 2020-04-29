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

const int MAXN = 1e5 + 5;

struct Task
{
    int x, y;
}a[MAXN], b[MAXN];
int vis[MAXN];
int n, m;

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; i++)
        {
            a[i].x = read<int>();
            a[i].y = read<int>();
        }
        for (int i = 0; i < m; i++)
        {
            b[i].x = read<int>();
            b[i].y = read<int>();
        }

        auto comp = [](const Task &a, const Task &b) -> bool
        {
            return a.x == b.x ? a.y > b.y : a.x > b.x;
        };
        sort(a, a + n, comp);
        sort(b, b + m, comp);

        int now = 0, cnt = 0; ll ans = 0;
        for (int i = 0; i < m; i++)
        {
            while (now < n && a[now].x >= b[i].x)
            {
                vis[a[now].y]++; now++;
            }
            for (int j = b[i].y; j <= 100; j++)
            {
                if (vis[j])
                {
                    cnt++; vis[j]--;
                    ans += 500ll * b[i].x + 2ll * b[i].y; break;
                }
            }
        }

        printf("%d %lld\n", cnt, ans);
    }

    return 0;
}

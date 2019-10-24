#include <bits/stdc++.h>
using namespace std;

struct N
{
    int x, y;
} a[1010];

int main()
{
    int t, n, inf = 1e8;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].x >> a[i].y;
        sort(a + 1, a + n + 1, [](N a, N b) -> bool {
            return a.x == b.x ? a.y < b.y : a.x < b.x;
        });
        printf("%d %d %d %d\n", a[n / 2].x + 1, a[n / 2].y - inf, a[n / 2 + 1].x - 1, a[n / 2 + 1].y + inf);
    }
}

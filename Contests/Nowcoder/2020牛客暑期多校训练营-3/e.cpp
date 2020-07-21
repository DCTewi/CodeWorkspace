#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

const int MAXN = 2e5 + 5;

struct Node 
{
    int i;
    ll value;
} a[MAXN];
int p[MAXN], n;
ll ans[2];

int main()
{
    int T = read<int>();
    while (T--)
    {
        ans[0] = ans[1] = 0;
        
        n = read<int>();
        for (int i = 1; i <= n; i++)
        {
            a[i].i = i;
            a[i].value = read<ll>();
        }

        sort(a + 1, a + n + 1, [](const Node &a, const Node &b)
        {
            return a.value == b.value ? a.i < b.i : a.value < b.value;
        });

        for (int i = 1; i <= n; i += 2)
        {
            ans[0] += abs(a[i].value - a[i + 1].value);
            // printf("%d %d %d %d %d\n", i, a[i].value, a[i + 1].value, abs(a[i].value - a[i + 1].value), ans[0]);
        }

        ans[1] = abs(a[1].value - a[3].value) + abs(a[n].value - a[n - 2].value);

        // printf("\t ans1 = %d\n", ans[1]);


        for (int i = 2; i < n - 2; i += 2)
        {
            ans[1] += abs(a[i].value - a[i + 3].value);
            // printf("%d, %d - %d %d %d %d %d\n", i, i + 3, a[i].value, a[i + 3].value, abs(a[i].value - a[i + 3].value), ans[1]);

        }

        printf("%lld\n", ans[0] + ans[1]);

    }
    return 0;
}

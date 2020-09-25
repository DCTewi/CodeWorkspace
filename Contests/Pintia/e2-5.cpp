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

int n, l;
int a[MAXN];
double ans;
int d[MAXN], s, t;

inline double getk(int q, int w)
{
    return 1.0 * (a[w] - a[q]) / (w - q);
}

int main()
{
    n = read<int>(), l = read<int>();
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + read<int>();
    }
    s = t = 1;
    for (int i = l; i <= n; i++)
    {
        while (s < t && getk(d[s], i) <= getk(d[s + 1], i)) s++;
        ans = max(ans, getk(d[s], i));

        while (s < t && getk(d[t - 1], d[t]) >= getk(d[t], i - l + 1)) t--;
        d[++t] = i - l + 1;
    }

    printf("%d\n", (int)(ans * 1000));
    return 0;
}

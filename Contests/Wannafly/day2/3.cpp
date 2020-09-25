#include <bits/stdc++.h>
using namespace std;

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

const int MAXN = 1e5 + 5;
int n = 0;
int p[MAXN], ans[MAXN], maxunder[MAXN];

int getw(int p, int q)
{
    int res = max(p, q) - min(p, q);
    return res * res;
}

int main()
{
    n = read<int>();
    ans[1] = n - 1;
    maxunder[1] = n;
    for (int i = 2; i <= n; i++)
    {
        maxunder[i] = i;
        p[i] = read<int>();
        for (int j = p[i]; j != 1; j = p[j])
        {
            ans[j] += getw(i, maxunder[j]);
            maxunder[j] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}

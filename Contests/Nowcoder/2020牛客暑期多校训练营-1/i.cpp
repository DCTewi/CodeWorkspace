#include <bits/stdc++.h>
using namespace std;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

const int MAXN = 5e1 + 5;
const int MAXM = 1e2 + 5;

int n, m;
int d[MAXN], a[MAXM], b[MAXM];

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; i++)
        {
            d[i] = read<int>();
        }
        for (int i = 0; i < m; i++)
        {
            a[i] = read<int>(); b[i] = read<int>();
        }
    }
    return 0;
}
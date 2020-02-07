#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int ch = getchar(), w = 0;
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

const int MAXN = 1e4 + 5;
int n, m;
int a[MAXN], b[MAXN];

int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        if (m + n == 0) return 0;

        for (int i = 0; i < n; i++)
        {
            int tmp = read<int>(); tmp = read<int>();
            a[i] =read<int>();
            b[i] = read<int>() + a[i];
        }
        while (m--)
        {
            int x = read<int>();
            int y = read<int>() + x;
            int ans = 0;
            
            for (int i = 0; i < n; i++)
            {
                if (b[i] > x && a[i] < y)
                {
                    ans++;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
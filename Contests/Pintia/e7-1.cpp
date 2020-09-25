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
int ans[MAXN], sum = 0;

void dfs(int s, int p)
{
    for (int i = ans[p - 1]; i <= s; i++)
    {
        if (i < n)
        {
            ans[p] = i;
            s -= i;
            if (!s)
            {
                sum++;
                printf("%d=", n);
                for (int i = 1; i < p; i++)
                {
                    printf("%d+", ans[i]);
                }
                printf("%d\n", ans[p]);
            }
            else
            {
                dfs(s, p + 1);
            }
            s += i;
        }
    }
}

int main()
{
    for (int i = 0; i <= MAXN; i++)
    {
        ans[i] = 1;
    }
    n = read<int>();
    dfs(n, 1);
    printf("%d=%d\n", n, n);
    printf("%d", sum);

    return 0;
}

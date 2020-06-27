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

int n, c;
vector<int> a, res;
int flag = 0, sum = 0;

void dfs(int now, int lef)
{
    if (flag) return;
    if (!lef)
    {
        flag = 1;
        for (int i : res)
        {
            printf("%d ", i);
        }
        return;
    }
    else
    {
        if (now == n) return;
        else
        {
            res.emplace_back(a[now]);
            if (lef - a[now] >= 0)
            {
                dfs(now + 1, lef - a[now]);
            }
            res.pop_back();

            if (lef >= 0)
            {
                dfs(now + 1, lef);
            }
        }
    }
}

int main()
{
    n = read<int>(), c = read<int>();
    a = vector<int>(n);
    for (int i = 0; i < n; i++) a[i] = read<int>(), sum += a[i];

    if (sum < c) return 0 * puts("No Solution!");

    dfs(0, c);
    if (!flag) puts("No Solution!");
    return 0;
}
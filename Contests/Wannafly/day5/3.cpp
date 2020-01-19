#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

const int MAXK = 5;
const int MAXN = 1e5 + 5;

int n, k;
set<int> s[MAXK];
map<int, int> times;
int num[8];
int ans = 0;

int main()
{
    n = read<int>(), k = read<int>();
    for (int i = 0; i < k; i++)
    {
        int m = read<int>();
        for (int j = 0; j < m; j++)
        {
            int x = read<int>();
            s[i].insert(x);
            times[x] |= 1 << i;
        }
    }
    if (k == 1)
    {
        printf("%d", (int)s[0].size());
        return 0;
    }
    else if (k == 2)
    {
        int ans = max(s[0].size(), s[1].size());
        printf("%d", max(ans, 1));
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (times.count(i))
        {
            num[times[i]]++;
        }
    }

    int delta = 0;
    delta = min(num[1], num[6]);
    num[1] = max(num[1] - delta, 0);

    delta = min(num[2], num[5]);
    num[2] = max(num[2] - delta, 0);

    delta = min(num[4], num[3]);
    num[4] = max(num[4] - delta, 0);

    ans = num[6] + num[5] + num[3] + max({num[1], num[2], num[4]}) + num[7];

    printf("%d", ans);

    return 0;
}
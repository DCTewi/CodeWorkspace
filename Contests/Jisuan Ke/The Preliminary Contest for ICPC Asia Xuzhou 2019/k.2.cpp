#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 5;
const int MAXMID = 1e6 + 10;

int n, ans = 1 << 30;
set<pair<int, int>> tile;
pair<int, int> poin[MAXN], midset[MAXMID];
int top = 0;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

inline pair<int, int> getmid(int a, int b)
{
    int x = (poin[a].first + poin[b].first) / 2;
    int y = (poin[a].second + poin[b].second) / 2;

    return make_pair(x, y);
}

inline pair<int, int> getthat(int a, pair<int, int> &mid)
{
    int x = 2 * mid.first - poin[a].first;
    int y = 2 * mid.second - poin[a].second;

    return make_pair(x, y);
}

int main()
{
    n = read<int>();
    if (n == 1)
    {
        return 0 * puts("0");
    }

    for (int i = 0; i < n; i++)
    {
        auto p = make_pair(read<int>() * 2, read<int>() * 2);

        tile.insert(p);
        poin[i] = p;

        for (int j = 0; j < i; j++)
        {
            auto mid = getmid(i, j);
            midset[top++] = mid;
        }

    }

        for (int i = 0; i < top; i++)
        {
            auto mid = midset[i];
            int now = 0;

            for (int k = 0; k < n; k++)
            {
                auto p = getthat(k, mid);
                if (!tile.count(p))
                {
                      now++;
                }
            }
            ans = min(ans, now);
        }

    printf("%d\n", ans);

    return 0;
}

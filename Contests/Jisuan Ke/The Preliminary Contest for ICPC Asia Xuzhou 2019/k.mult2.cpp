#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, ans = 1 << 30;
set<pair<int, int>> tile;
vector<pair<int, int>> poin;

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
    poin = vector<pair<int, int>>(n);
    for (int i = 0; i < n; i++)
    {
        auto p = make_pair(read<int>() * 2, read<int>() * 2);

        tile.insert(p);
        poin[i] = p;
    }

    for (int l = 0; l < n; l++)
    {
        for (int r = l + 1; r < n; r++)
        {
            set<pair<int, int>> used;

            printf("Tot mid between %d,%d -- %d,%d\n", poin[l].first, poin[l].second, poin[r].first, poin[r].second);
            auto mid = getmid(l, r);
            printf("Use %d,%d as center\n", mid.first, mid.second);
            int now = 0;

            for (int k = 0; k < n; k++)
            {
                if (k == l || k == r) continue;

                auto p = getthat(k, mid);
                printf("We need %d,%d\n", p.first, p.second);
                if (!tile.count(p))
                {
                    if (!used.count(p))
                    {
                        used.insert(p); now++;
                    }
                }
            }

            printf("Ans %d, now %d\n\n", ans, now);
            ans = min(ans, now);
        }
    }

    printf("%d\n", ans);

    return 0;
}


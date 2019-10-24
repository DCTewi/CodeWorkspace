#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, ans = 1 << 30;
set<pair<double, double>> tile;
vector<pair<double, double>> poin;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

inline pair<double, double> getmid(int a, int b)
{
    double x = (poin[a].first + poin[b].first) / 2;
    double y = (poin[a].second + poin[b].second) / 2;

    return make_pair(x, y);
}

inline pair<double, double> getthat(int a, pair<double, double> &mid)
{
    double x = 2 * mid.first - poin[a].first;
    double y = 2 * mid.second - poin[a].second;

    return make_pair(x, y);
}

int main()
{
    n = read<int>();
    poin = vector<pair<double, double>>(n);
    for (int i = 0; i < n; i++)
    {
        double u, v;
        scanf("%lf%lf", &u, &v);
        auto p = make_pair(u, v);

        tile.insert(p);
        poin[i] = p;
    }

    for (int l = 0; l < n; l++)
    {
        for (int r = 0; r < n; r++)
        {
            if (l == r) continue;
            printf("Tot mid between %f,%f -- %f,%f\n", poin[l].first, poin[l].second, poin[r].first, poin[r].second);
            auto mid = getmid(l, r);
            printf("Use %f,%f as center\n", mid.first, mid.second);
            int now = 0;

            for (int k = 0; k < n; k++)
            {
                if (k == l || k == r) continue;

                auto p = getthat(k, mid);
                printf("We need %f,%f\n", p.first, p.second);
                if (!tile.count(p)) now++;
            }

            printf("Ans %d, now %d\n\n", ans, now);
            ans = min(ans, now);
        }
    }

    printf("%d\n", ans);

    return 0;
}


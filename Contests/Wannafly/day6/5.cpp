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

const int MAXN = 1e2 + 5;
const int MAXW = 5e3 + 5;
const int INF = 998244353;
const int TOT = 1000000;

int n, m, w;
struct Data
{
    int id, res;
    Data(int y, int c) : id(y), res(c) {}
};
vector<Data> dat[MAXN];
set<int> ac[MAXN], whoac[MAXN];
int ans[MAXN];

int main()
{
    n = read<int>(), m = read<int>(), w = read<int>();
    for (int i = 0; i < w; i++)
    {
        int x = read<int>(), y = read<int>(), c = read<int>();
        dat[x].emplace_back(Data(y, c));
        if (c) ac[x].insert(y), whoac[y].insert(x);
    }

    for (int i = 1; i <= n; i++)
    {
        // printf("No %d aced %d\n", i, ac[i].size());
        int acn = ac[i].size();
        if ((int)dat[i].size() == 0) // Rule 1
        {
            ans[i] = INF;
        }
        else if (acn == 0) // Rule 2
        {
            ans[i] = TOT;
        }
        else if (acn == m) // Rule 3
        {
            ans[i] = 0;
        }
        else
        {
            for (int p = 1; p <= m; p++)
            {
                if (ac[i].count(p) == 0)
                {
                    if (whoac[p].size()) ans[i] += 20; // Rule 4
                    if (whoac[p].size() >= n / 2) ans[i] += 10; // Rule 5
                }
            }
            vector<pair<int, int>> maxk;
            dat[i].emplace_back(Data(0, 1));
            for (int j = 0, k = 1, now = 0; j < dat[i].size(); j++)
            {
                if (dat[i][j].res == 0)
                {
                    if (dat[i][j].id != now)
                    {
                        if (now && k) maxk.emplace_back(make_pair(now, k));
                        k = 1; now = dat[i][j].id;
                    }
                    else k++;
                }
                else
                {
                    if (now != 0) maxk.emplace_back(make_pair(now, k));
                    k = now = 0;
                }
            }
            for (auto p : maxk)
            {
                // printf("For %d, at %d, maxk = %d\n", i, p.first, p.second);
                ans[i] += p.second * p.second; // Rule 6
                if (ac[i].count(p.first) == 0 && whoac[p.first].size())
                {
                    ans[i] += p.second * p.second; // Rule 7
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d", ans[i]);
        if (i < n) printf("\n");
    }

    return 0;
}
/**
4 3 22
1 1 1
1 2 1
1 3 1
2 1 0
2 1 0
2 1 1
2 2 0
3 1 0
3 1 0
3 1 0
3 2 1
3 2 0
3 2 0
3 1 0
3 1 0
3 1 0
3 1 0
3 1 1
3 1 1
3 1 1
3 1 1
3 3 1

 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;

map<pair<string, string>, pair<int, pair<int, int>>> csv;
string dat[MAXN][15];
int n, m;

void reads(string &res)
{
    char ch = getchar();
    while (ch > 126 || ch < 32 || ch == ',' || ch == EOF)
    {
        ch = getchar();
    }
    while (ch >= 32 && ch <= 128 && ch != ',' && ch != EOF)
    {
        res += ch;
        ch = getchar();
    }
}

int main()
{
    freopen("database.in", "r", stdin);
    freopen("database.out", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            reads(dat[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int p = 1; p <= m; p++)
        {
            for (int q = p + 1; q <= m; q++)
            {
                auto pr = make_pair(dat[i][p], dat[i][q]);
                if (csv.count(pr))
                {
                    auto col = csv[pr].second;
                    if (col.first == p && col.second == q)
                    {
                        printf("NO\n%d %d\n%d %d\n", csv[pr].first, i, p, q);
                        return 0;
                    }
                }
                else
                {
                    csv[pr] = make_pair(i, make_pair(p, q));
                }
            }
        }
    }

    puts("YES");

    return 0;
}


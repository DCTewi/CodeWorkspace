// WA
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int n, m;
int tile[MAXN][MAXN], siz[MAXN][MAXN];
int ans = -1, x, y, h;

void get_siz()
{
    memset(siz, 0, sizeof(siz));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            siz[i][j] = (tile[i][j] == 0)? 0: siz[i][j - 1] + 1;
        }
    }
}

void get_max()
{
    get_siz();
    int res = 0, nx = 0, ny = 0, nh = 0;
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1, mind = -1, len = 0; i <= n; i++)
        {
            if (siz[i][j])
            {
                len++;
                mind = (~mind)? min(mind, siz[i][j]): siz[i][j];
                int now = len * mind;
                if (now != ans || !(x == i && y == j && mind == h))
                {
                    // cout << "\tupdate" << now << "\n";
                    res = now, nx = i, ny = j, nh = mind;
                }
            }
            else
            {
                len = 0; mind = -1;
            }
        }
    }

    ans = res, x = nx, y = ny, h = nh;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string tmp; cin >> tmp;
        for (int j = 1; j <= m; j++)
        {
            tile[i][j] = tmp[j - 1] - '0';
        }
    }

    get_max();
    get_max();

    cout << (ans) << "\n";

    return 0;
}

// WA
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int n, m;
int tile[MAXN][MAXN], siz[MAXN][MAXN];
priority_queue<int, vector<int>, less<int>> q;
set<int> vis;

int get_dep(int i, int j)
{
    int res = 0;
    while (tile[i][j])
    {
        res++; i--;
    }
    return res;
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
            siz[i][j] = (tile[i][j]? siz[i][j - 1] + 1: 0);
            q.push(siz[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int res = min(siz[i - 1][j], siz[i][j]);
            if (res) res *= get_dep(i, j);

            // cout << i << " " << j << ":" << siz[i][j] << endl;

            q.push(res);
        }
    }

    q.pop();
    cout << (q.size()? q.top(): 0) << "\n";

    // while (q.size())
    // {
    //     cout << q.top() << " "; q.pop();
    // }

    return 0;
}

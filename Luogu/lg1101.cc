#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;
const int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[8] = {1, -1, -1, 1, 0, 0, -1, 1};
const string dic = "yizhong"; 

string mat[MAXN], ans[MAXN];
int n;

bool find(int x, int y, int k)
{
    int nx = x, ny = y;
    for (int i = 0; i < 7; i++)
    {
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) return false;

        if (mat[nx][ny] != dic[i]) return false;

        nx += dx[k]; ny += dy[k];
    }
    return true;
}

void put_string(int x, int y, int k)
{
    int nx = x, ny = y;
    for (int i = 0; i < 7; i++)
    {
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) return;

        ans[nx][ny] = dic[i];

        nx += dx[k]; ny += dy[k];
    }
}

int main()
{
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
        ans[i] = string(n, '*');
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 'y')
            {
                for (int k = 0; k < 8; k++)
                {
                    if (find(i, j, k))
                    {
                        put_string(i, j, k);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}

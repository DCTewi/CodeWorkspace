// K - Tetris # WA
#include <bits/stdc++.h>
using namespace std;

int n, m;
int tile[20][20], dic[4];
int path[4][4][2] = 
{
    {
        {0, 0}, {0, 1}, {0, 2}, {1, 1}
    },
    {
        {1, 0}, {2, 0}, {3, 0}, {2, 1}
    },
    {
        {0, 3}, {1, 3}, {2, 3}, {1, 2}
    },
    {
        {3, 1}, {3, 2}, {3, 3}, {2, 2}
    }
};

bool check_diff(int x, int y)
{
    if (dic[0] == tile[x - 1][y] || dic[0] == tile[x][y - 1]) return false;
    if (dic[1] == tile[x + 4][y] || dic[1] == tile[x + 3][y - 1]) return false;
    if (dic[2] == tile[x][y + 4] || dic[2] == tile[x - 1][y + 3]) return false;
    if (dic[3] == tile[x + 4][y + 3] || dic[3] == tile[x + 3][y + 4])return puts("0"), false;
    return true;
}

void put_block(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        dic[i] = i + 1;
        // cout << "dic[" << i << "] = " << dic[i] << "\n";
    }
    while (!check_diff(x, y))
    {
        // for (int i = 0; i < 4; i++) cout << dic[i] << " "; cout << "\n";
        next_permutation(dic, dic + 4);
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int nx = x + path[i][j][0], ny = y + path[i][j][1];
            tile[nx][ny] = dic[i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);

    while (cin >> n >> m)
    {
        memset(tile, 0, sizeof(tile));
        if (n % 4 || m % 4) return cout << "no response\n", 0;

        for (int i = 1; i <= n; i += 4)
        {
            for (int j = 1; j <= m; j += 4)
            {
                put_block(i, j);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << tile[i][j] << "\0\n"[j == m];
            }
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1511;
char board[MAXN][MAXN];
bool map1[MAXN * 2][MAXN * 2], map2[MAXN][MAXN];
int n, m, dn, dm;

bool dfs(int x,int y)
{
    if(x == -1)
    {
        if(dfs(dn - 1, y))return true;
        return false;
    }
    else if(x == dn)
    {
        if(dfs(0, y))return true;
        return false;
    }
    else if(y == -1)
    {
        if(dfs(x, dm - 1))return true;
        return false;
    }
    else if(y == dm)
    {
        if(dfs(x, 0))return true;
        return false;
    }
    else if(map1[x][y] || board[x % n][y % m] == '#')
    {
        return false;
    }
    else if(map2[x % n][y % m])
    {
        return true;
    }


    map1[x][y] = true;
    map2[x % n][y % m] = true;

    return dfs(x + 1, y)? true: dfs(x - 1, y)? true: dfs(x, y + 1)? true: dfs(x, y - 1)? true: false;

}

int main()
{
    while(cin >> n >> m)
    {
        dn = n * 2;
        dm = m * 2;
        int sx, sy;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> board[i][j];
                if(board[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
            }
        }
        memset(map1, 0, sizeof(map1));
        memset(map2, 0, sizeof(map2));
        if(dfs(sx, sy))    printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
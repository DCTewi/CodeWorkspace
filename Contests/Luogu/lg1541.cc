#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e2 + 5;
const int MAXM = 4e1 + 5;
int n, m, top = 0;
int path[MAXN], card[5];
int f[MAXM][MAXM][MAXM][MAXM];

inline int Max(int a, int b, int c, int d, int e)
{
    return max(a, max(b, max(c, max(d, e))));
}

void DebugPrint()
{
    for (int i = 0; i < 5; i++)
    {
        cout<<"card["<<i<<"] is "<<card[i]<<endl;
    }
    for (int i = 0; i <= card[1]; i++)
    {
        for (int j = 0; j <= card[2]; j++)
        {
            for (int k = 0; k <= card[3]; k++)
            {
                for (int l = 0; l <= card[4]; l++)
                {
                    cout<<"f["<<i<<", "<<j<<", "<<k<<", "<<l<<"]: "<<f[i][j][k][l]<<" ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>path[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int x; cin>>x;
        card[x]++;
    }
    
    for (int i = 0; i <= card[1]; i++)
    {
        for (int j = 0; j <= card[2]; j++)
        {
            for (int k = 0; k <= card[3]; k++)
            {
                for (int l = 0; l <= card[4]; l++)
                {
                    f[i][j][k][l] = Max
                    (
                        f[i][j][k][l],
                        f[(i - 1 < 0)? 0: i - 1][j][k][l] + path[i * 1 + j * 2 + k * 3 + l * 4 + 1],
                        f[i][(j - 1 < 0)? 0: j - 1][k][l] + path[i * 1 + j * 2 + k * 3 + l * 4 + 1],
                        f[i][j][(k - 1 < 0)? 0: k - 1][l] + path[i * 1 + j * 2 + k * 3 + l * 4 + 1],
                        f[i][j][k][(l - 1 < 0)? 0: l - 1] + path[i * 1 + j * 2 + k * 3 + l * 4 + 1]
                    );
                }
            }
        }
    }
    
    cout<<f[card[1]][card[2]][card[3]][card[4]]<<endl;
    
    return 0;
}

// WA 8
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 8e1 + 5;
int n, m;
ll a[MAXN][MAXN];
ll f[MAXN][MAXN]; // f[time][row] = max(front, tail);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>a[i][j];
        }
    }

    ll row = 1;
    for (int i = 1; i <= m; i++)
    {
        row <<= 1;
        for (int j = 1; j <= n; j++)
        {
            int top = 1; while (a[j][top] == -1) top++;
            int bak = m; while (a[j][bak] == -1) bak--;
            if (a[j][top] < a[j][bak])
            {
                f[i][j] = f[i][j - 1] + a[j][top] * row;
                a[j][top] = -1;
            }
            else
            {
                f[i][j] = f[i][j - 1] + a[j][bak] * row;
                a[j][bak] = -1;
            }
            if (j == n)
            {
                f[i][j] += f[i - 1][n];
            }
        }
    }

    cout<<f[m][n]<<"\n";

    return 0;
}
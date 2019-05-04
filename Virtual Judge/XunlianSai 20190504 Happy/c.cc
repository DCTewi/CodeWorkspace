#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e2 + 5;
ll a[MAXN][MAXN], b[MAXN][MAXN];
ll n;

int main()
{
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (b[i][j] > b[i][k] + b[k][j])
                {
                    b[i][j] = b[i][k] + b[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (b[i][j] != a[i][j])
            {
                cout << "-1\n";
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << (j == n? "\n": " ");
        }
    }

    return 0;
}
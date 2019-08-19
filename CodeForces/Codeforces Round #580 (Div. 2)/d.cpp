#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const int INF = 1 << 30;
int n, cnt = 0;
ll a[MAXN];

vector<int> val[MAXN], dis[MAXN];
int ans = 0;
inline void spfa()
{
    ans = val[0][0];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j) dis[i][j] = val[i][j];
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i < k; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                ans = min(ans, dis[i][j] + val[i][k] + val[k][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        val[i] = dis[i] = vector<int>(n + 1, 0x3f3f3f3f);
        cin >> a[i];
        for (int j = 1; j < i; j++)
        {
            if (a[i] & a[j])
            {
                val[i][j] = val[j][i] = 1; cnt++;
            }
        }
    }
    if (cnt == 0) cout << "-1\n";
    else
    {
        spfa();
        if (ans == val[0][0]) cout << "-1\n";
        else cout << ans << "\n";
    }
    return 0;
}


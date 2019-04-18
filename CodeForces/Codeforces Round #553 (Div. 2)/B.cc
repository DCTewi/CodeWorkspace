// Nooooooooooooooooo
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXA = 1e3 + 50;
const int MAXN = 5e2 + 5;
int n, m;
int a[MAXN][MAXN];
int ans[MAXN], top = 0, outed= 0;
map<int, int> num;

void dfs(int now)
{
    if (outed) return;
    if (now > n)
    {
        int res = 0;
        for (int i = 1; i <= top; i++)
        {
            res ^= a[i][ans[i]];
        }
        if (res)
        {
            puts("TAK");
            for (int i = 1; i <= top; i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
            outed = 1;
        }
        return;
    }

    for (int i = 1; i <= m; i++)
    {
        ans[++top] = i;

        dfs(now + 1);

        top--;
        if (outed) return;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>a[i][j];
            num[a[i][j]]++;
        }
    }

    int flag = 0;
    for (auto &it : num)
    {
        if (it.second & 1)
        {
            flag = 1;
            break;
        }
    }
    if (!flag) return 0 * puts("NIE");

    dfs(1);

    if (!outed) puts("NIE");

    return 0;
}

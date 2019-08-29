#include <string>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

const int MAXN = 10;
int n, k;
string a[MAXN];
int ans = 0;

int visx[MAXN], visy[MAXN], cnt = 0;
void dfs(int now)
{
    if (cnt == k)
    {
        ans++; return;
    }
    if (now >= n) return;
    for (int i = 0; i < n; i++)
    {
        if (a[now][i] == '#' && !visx[i] && !visy[i])
        {
            visx[i] = visy[i] = 1;
            cnt++;
            dfs(now + 1);
            visx[i] = visy[i] = 0;
            cnt--;
        }
    }
    dfs(now + 1);
}

int main()
{
    //ios::sync_with_stdio(0); 

    while (cin >> n >> k)
    {
        if (n == -1 && k == -1) return 0;

        memset(visx, 0, sizeof(visx));
        memset(visy, 0, sizeof(visy));
        ans = cnt = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        dfs(0);

        cout << ans << "\n";
    }

    return 0;
}

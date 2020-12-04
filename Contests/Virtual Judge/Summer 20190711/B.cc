// B - Chess 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int vis[25] = {0};
            int num; cin >> num;
            for (int j = 1; j <= num; j++)
            {
                int in; cin >> in;
                vis[in] = 1;
            }
            int odd = 0, tot = 0;
            for (int j = 20; j >= 0; j--)
            {
                if (!vis[j])
                {
                    if (tot)
                    {
                        res ^= tot; tot = 0;
                    }
                    odd ^= 1;
                }
                else if (odd)
                {
                    tot++;
                }
            }
            if (tot)
            {
                res ^= tot;
            }
        }

        if (res) puts("YES");
        else puts("NO");
    }
    return 0;
}

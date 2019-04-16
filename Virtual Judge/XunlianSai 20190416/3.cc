// j wa
#include <bits/stdc++.h>
using namespace std;

int t, n;
int now = 0, ans = 0;
char dir = 0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t>>n;

    for (int i = 0; i < n; i++)
    {
        char nd; int a, r;
        cin>>nd>>a>>r;
        if (!dir)
        {
            dir = nd;
            now = a;
        }
        else if (dir == nd)
        {
            if (now + 3 > a + r)
            {
                ans++;
                now += 3;
            }
            now = a;
        }
        else if (dir != nd)
        {
            dir = nd;
            if (now + t > a + r)
            {
                ans++;
                now += t;
            }
            now = a;
        }
    }

    cout<<ans<<"\n";

    return 0;
}
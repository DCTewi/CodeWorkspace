// j wa 2
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e2 + 5;
const int MAXA = 9e4 + 5;

int t, n;
int now = 0, ans = 0;
char dir = 0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t>>n;

    while (n--)
    {
        char ch; int a, r;
        cin>>ch>>a>>r;
        
        if (!dir)
        {
            dir = ch;
            now = a;
        }
        else if (dir == ch)
        {
            if (now + 3 > a + r)
            {
                puts("1!");
                ans++;
                now += 3;
            }
            else
            {
                now = max(now + 3, a);
            }
        }
        else if (dir != ch)
        {
            dir = ch;
            if (now + t > a + r)
            {
                puts("2!");
                ans++;
                now += t;
            }
            else
            {
                now = max(now + t, a);
            }
        }

        cout<<now<<endl;
    }

    cout<<ans<<"\n";

    return 0;
}
//e
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int h[MAXN];
int ans = 1 << 25, n = 0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>h[i];
    }
    sort(h + 1, h + n + 1);

    ans = min(h[n], n);
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, h[i] + n - i);
    }

    cout<<ans<<"\n";
    return 0;

}
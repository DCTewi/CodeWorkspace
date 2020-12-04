#include <cstdio>
#include <iostream>

using namespace std;
const int MAX = 105;
int main()
{
    int n, k, ans = 0;
    int a[MAX];

    cin>>n>>k;
    for (int i = 0; i < n; i++) cin>>a[i];

    int zhengxiang = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > k) break;
        zhengxiang = i;
        ans++;
    }

    int fanxiang = 0;
    if (zhengxiang != n - 1)
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > k) break;
        fanxiang = i;
        ans++;
    }

    cout<<ans<<endl;

    return 0;
}

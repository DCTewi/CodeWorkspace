#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, ans = 0;

int main()
{
    freopen("auxiliary.in", "r", stdin);
    freopen("auxiliary.out", "w", stdout);
    cin >> n;

    ans += (n / 3) * 7;
    n %= 3;

    if (n == 1)
    {
        ans -= 3;
    }
    else if (n == 2)
    {
        ans += 1;
    }

    printf("%d\n", ans);

    return 0;
}

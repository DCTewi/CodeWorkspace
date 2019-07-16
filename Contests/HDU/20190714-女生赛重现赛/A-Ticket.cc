// A - Ticket
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int n;
double a[MAXN], ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (ans >= 400) ;
        else if (ans >= 150) a[i] *= 0.5;
        else if (ans >= 100) a[i] *= 0.8;

        ans += a[i];
    }

    cout << fixed << setprecision(2) << ans << "\n";

    return 0;
}

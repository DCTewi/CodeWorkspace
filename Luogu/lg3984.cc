#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int a[MAXN];
int n, t, ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        ans += min(t, a[i] - a[i - 1]);
    }

    cout << ans + t << "\n";
}

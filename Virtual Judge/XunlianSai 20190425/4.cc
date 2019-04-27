// e wa
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 2; i < n; i++)
        {
            if (a[i] - a[i - 1] > 0 != a[i - 1] - a[i - 2] > 0)
            {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
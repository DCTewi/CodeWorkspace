// h
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int a[MAXN];

int main()
{
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        int ans = 0, hole = 0;
        set<int> hill;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 2; i < n; i++)
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                hill.insert(i);
            }
        }
        for (int i = 2; i < n; i++)
        {
            if (a[i] < a[i - 1] && a[i] < a[i + 1] && hill.count(i - 1) && hill.count(i + 1) && a[i - 1] == a[i + 1])
            {
                hole = i;
                break;
            }
        }
        for (int i = 2; i < n; i++)
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                ans++;
            }
        }

        if (hole) cout << max(0, ans - 2) << "\n";
        else
        {
            int flg = 0;
            for (auto &x : hill)
            {
                if (x - 2 < 1 || x + 2 > n)
                {
                    flg = 1;
                    cout << max(0, ans - 1) << "\n" ;
                    break;
                }
                if (a[x - 1] > a[x - 2] && a[x - 1] > a[x + 1]) continue;
                if (a[x + 1] > a[x - 1] && a[x + 1] > a[x + 2]) continue;
                else
                {
                    flg = 1;
                    cout << max(0, ans - 1) << "\n";
                    break;
                }
            }
            if (!flg) cout << ans << "\n";
        }
    }

    return 0;
}
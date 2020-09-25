// TLE
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    int Q; cin >> Q;
    while (Q--)
    {
        int n; cin >> n;
        vector<int> a(n * 4);

        for (int i = 0; i < n * 4; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int l = 0, r = n * 4 - 1, siz = -1, flag = 0;
        while (l < r)
        {
            if (a[l + 1] == a[l] && a[r - 1] == a[r] && l + 1 != r - 1)
            {
                int now = a[l] * a[r];
                if (siz == -1) siz = now;
                else if (siz != now)
                {
                    flag = 1; break;
                }
                l += 2; r -= 2;
            }
            else
            {
                if (a[l + 1] != a[l]) l++;
                if (a[r - 1] != a[r]) r--;
            }
        }
        if (flag) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}

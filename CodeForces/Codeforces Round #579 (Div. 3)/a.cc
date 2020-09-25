#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    int Q; cin >> Q;
    while (Q--)
    {
        int n, minn = 1 << 30, minid = -1; cin >> n;
        vector<int> a(n + 5);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] < minn)
            {
                minn = a[i]; minid = i;
            }
        }

        int flag = 0;
        for (int i = 1, j = minid; i <= n; i++)
        {
            if (a[j] != i)
            {
                flag = 1; break;
            }
            (j == n)? j = 1: j++;
        }
        if (flag)
        {
            flag = 0;
            for (int i = 1, j = minid; i <= n; i++)
            {
                if (a[j] != i)
                {
                    flag = 1; break;
                }
                (j == 1)? j = n: j--;
            }
        }
        if (flag) cout << "NO\n";
        else cout << "YES\n";

    }
    return 0;
}

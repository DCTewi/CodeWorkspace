#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200010];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), a[i] %= 2, a[i] ^= a[i - 1];
        if (k % 2 != a[n])
        {
            puts("NO");
            continue;
        }
        vector<int> v;
        int now = 1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == now && v.size() < k - 1)
            {
                v.push_back(i);
                now = 1 - now;
            }
        }
        if (v.size() == k - 1)
        {
            v.push_back(n);
            puts("YES");
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << " ";
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int len[MAXN];

int main()
{
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> len[i];
        }
        sort(len, len + n);
        cout << min(len[n - 2] - 1, n - 2) << "\n";
    }

    return 0;
}
// 2 2 3 3 4

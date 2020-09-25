// NOOOO
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 5;
int n, k;
ll a[MAXN];
ll st1[MAXN][30], st2[MAXN][30];

void build()
{
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; (i + (1 << j) - 1) <= n; i++)
        {
            st1[i][j] = max(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]);
            st2[i][j] = min(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r)
{
    int k = floor(log((double)(r - l + 1)) / log((double)(2)));
    return max(st1[l][k], st1[r - (1 << k) + 1][k]) - min(st2[l][k], st2[r - (1 << k) + 1][k]);
}

int main()
{
    ios::sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        st1[i][0] = st2[i][0] = a[i];
    }
    build();

    cout << query(1, n + 1) << ", " << query(1, n / 2) << "\n";

    if (k == n)
    {
        cout << "0\n";
        return 0;
    }

    return 0;
}

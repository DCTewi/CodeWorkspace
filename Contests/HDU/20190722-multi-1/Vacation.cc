#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
LL l[100005], s[100005], v[100005];

double headt(int i, int dis)
{
    double ht = (s[i] - dis) / (double)v[i];
    if (i == n)
        return ht;
    else
    {
        return max(headt(i + 1, dis - l[i + 1]), ht);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cout << setprecision(18);
    while (cin >> n)
    {
        LL sum = 0;
        for (int i = 0; i <= n; ++i)
            cin >> l[i];
        for (int i = 0; i <= n; ++i)
            cin >> s[i];
        for (int i = 0; i <= n; ++i)
            cin >> v[i];
        cout << headt(0, 0) << '\n';
    }

    return 0;
}
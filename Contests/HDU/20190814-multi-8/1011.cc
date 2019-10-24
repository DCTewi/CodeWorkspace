#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read()
{
    ll x = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    ll T = read();
    while (T--)
    {
        ll n = read();
        vector<pair<ll, ll>> a(n);

        for (int i = 0; i < n; i++)
        {
            a[i].second = read();
            a[i].first = read();
        }

        sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b)
                {
                    return a > b;
                });

        ll ans = 0, p = 0;
        for (int i = 0; i < n; i++)
        {
            int j = p, flag = 0;

            for (; a[i].second && j < n; j++)
            {
                if (j == i)
                {
                    p = i; flag = 1; continue;
                }

                if (a[i].second < a[j].first)
                {
                    ans += a[i].second;
                    a[j].first -= a[i].second; a[i].second = 0;
                }
                else
                {
                    if (!flag) p = j + 1;
                    ans += a[j].first;
                    a[i].second -= a[j].first; a[j].first = 0;
                }
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}


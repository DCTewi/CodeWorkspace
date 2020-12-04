#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

const int INF = 1 << 30;

int n;

int l = INF, r = -INF, b = INF, t = -INF;

int circ = 0;

int main()
{
    freopen("intel.in", "r", stdin);
    freopen("intel.out", "w", stdout);
    n = read<int>(); 
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].first = read<int>();
        v[i].second = read<int>();

        l = min(l, v[i].first);
        r = max(r, v[i].first);
        b = min(b, v[i].second);
        t = max(t, v[i].second);

        if (i)
        {
            int delta = 0;
            if (v[i - 1].first == v[i].first)
            {
                delta = v[i - 1].second - v[i].second;
            }
            else
            {
                delta = v[i - 1].first - v[i].first;
            }
            circ += abs(delta);
        }
    }
    
    int delta = 0;
    if (v[0].first == v[n - 1].first)
    {
        delta = v[0].second - v[n - 1].second;
    }
    else
    {
        delta = v[0].first - v[n - 1].first;
    }
    circ += abs(delta);

    int ans = circ - (r - l) * 2 - (t - b) * 2;

    printf("%d %d %d\n", circ,(r - l) * 2 + (t - b) * 2,  ans);

    return 0;
}

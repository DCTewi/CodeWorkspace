// qifashi hebing
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
ll n = 0;
ll p[MAXN];
vector<ll> edges[MAXN];
set<ll> s[MAXN];
ll ans[MAXN], out[MAXN];

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

void dfs(ll u, ll fa = -1)
{
    for (int i = 0; i < edges[u].size(); i++)
    {
        ll v = edges[u][i];
        if (v == fa) continue;
        dfs(v, u);

        if (s[u].size() < s[v].size()) // swap to keep s[u] bigger
        {
            swap(s[u], s[v]); ans[u] = ans[v];
        }

        for (auto j = s[v].begin(); j != s[v].end(); j++)
        {
            if ((*j) <= (*s[u].begin())) // less than all
            {
                ans[u] += ((*s[u].begin()) - (*j)) * ((*s[u].begin()) - (*j));
            }
            else if ((*j) >= (*s[u].rbegin())) // bigger than all
            {
                ans[u] += ((*j) - (*s[u].rbegin())) * ((*j) - (*s[u].rbegin()));
            }
            else // middle of all
            {
                auto k1 = s[u].lower_bound(*j);
                auto k2 = k1; k2--;
                ans[u] -= ((*k1) - (*k2)) * ((*k1) - (*k2)); // old
                ans[u] += ((*k1) - (*j)) * ((*k1) - (*j)); // new
                ans[u] += ((*j) - (*k2)) * ((*j) - (*k2)); // new
            }
            s[u].insert(*j);
        }
        //s[v].clear();
    }
    out[u] = ans[u];
}

int main()
{
    n = read<ll>();
    for (int i = 2; i <= n; i++)
    {
        p[i] = read<ll>();
        edges[i].emplace_back(p[i]);
        edges[p[i]].emplace_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        s[i].insert(i);
    }
    dfs(1, -1);

    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", out[i]);
    }
    return 0;
}

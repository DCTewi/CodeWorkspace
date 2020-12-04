#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

const int MAXM = 3e5 + 5;
const int MOD = 998244353;

// Graph
struct Edge
{
    int to, next;
    Edge (int v = 0, int h = 0): to(v), next(h) {}
} edge[MAXM << 2];
int head[MAXM];
void add_edge(int u, int v)
{
    static int cnt = 0;
    cnt++;
    edge[cnt] = Edge(v, head[u]);
    head[u] = cnt;
}

// Tarjan
vector<int> res;
int pre[MAXM], dfn[MAXM], top = 0;
void tarjan(int u)
{
    dfn[u] = ++top;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == pre[u]) continue;

        if (!dfn[v])
        {
            pre[v] = u;
            tarjan(v);
        }
        else if (dfn[v] > dfn[u])
        {
            int now = v, num = 1;
            while (now != u)
            {
                num++;
                now = pre[now];
            }
            res.emplace_back(num);
        }
    }
}

// QPow
ll q_pow(ll a, ll k, ll mod)
{
	if (!k) return 1;

	ll ans = 1;
	while (k)
	{
		if (k & 1) ans = ans * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return ans;
}

// Main
int main()
{
    int n = read<int>(), m = read<int>();
    for (int i = 0; i < m; i++)
    {
        int u = read<int>(), v = read<int>();
        add_edge(u, v);
        add_edge(v, u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i);
        }
    }

    ll ans = 1, cnt = m;
    for (int k : res)
    {
        ans = ans * (q_pow(2, k, MOD) - 1) % MOD;
        cnt -= k;
    }

    ans = ans * q_pow(2, cnt, MOD) % MOD;

    printf("%lld\n", ans);

    return 0;
}

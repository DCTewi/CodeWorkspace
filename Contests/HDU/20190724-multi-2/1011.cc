#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const int MAXT = 3e6 + 5;

struct Node
{
    ll l, r, sum;
} tree[MAXT];
ll a[MAXN], number[MAXN], root[MAXN], node_num;
ll n, m, num;

void maketree(ll l, ll r, ll &node)
{
    node = ++node_num;
    if (l == r)
        return;
    ll mid = (l + r) >> 1;
    maketree(l, mid, tree[node].l);
    maketree(mid + 1, r, tree[node].r);
}

void addtree(ll l, ll r, ll &node, ll pre, ll pos)
{
    node = ++node_num;
    tree[node] = tree[pre];
    tree[node].sum++;
    if (l == r) return;
    ll mid = (l + r) >> 1;
    if (pos <= mid)
        addtree(l, mid, tree[node].l, tree[pre].l, pos);
    else
        addtree(mid + 1, r, tree[node].r, tree[pre].r, pos);
}

ll query(ll l, ll r, ll node, ll pre, ll k)
{
    if (l == r) return l;
    ll chal = tree[tree[node].l].sum - tree[tree[pre].l].sum;
    ll mid = (l + r) >> 1;
    if (k <= chal)
        return query(l, mid, tree[node].l, tree[pre].l, k);
    else
        return query(mid + 1, r, tree[node].r, tree[pre].r, k - chal);
}

void init()
{
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        number[i] = a[i];
    }
    sort(number + 1, number + 1 + n);
    num = unique(number + 1, number + 1 + n) - number - 1;

    node_num = 0;
    maketree(1, num, root[0]);
    for (ll i = 1; i <= n; i++)
    {
        ll pos = lower_bound(number + 1, number + 1 + num, a[i]) - number;
        addtree(1, num, root[i], root[i - 1], pos);
    }
}

inline ll get_kth(ll l, ll r, ll k)
{
    return number[query(1, num, root[r], root[l - 1], r - l + 2 - k)];
}
// a > b, c
inline bool check(ll a, ll b, ll c)
{
    return a < (b + c);
}

int main()
{
    // freopen("in.txt", "r", stdin);
    while (~scanf("%lld%lld", &n, &m))
    {
        init();
        while (m--)
        {
            ll l, r;
            scanf("%lld%lld", &l, &r);
            // cout << get_kth(l, r, 1) << " " << get_kth(l, r, 2) << " " << get_kth(l, r, 3) << endl;
            ll maxl[3] = {get_kth(l, r, 1), get_kth(l, r, 2), get_kth(l, r, 3)};
            bool flag = false;
            for (ll k = 1; k < r - l; k++)
            {
                if (check(maxl[0], maxl[1], maxl[2]))
                {
                    flag = true;
                    break;
                }
                maxl[0] = maxl[1], maxl[1] = maxl[2];
                maxl[2] = get_kth(l, r, k + 3);
            }
            if (flag)
                printf("%lld\n", maxl[0] + maxl[1] + maxl[2]);
            else
                puts("-1");
        }
    }

    return 0;
}

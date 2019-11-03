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

const int MAXN = 1e5 + 5;

struct SegTree
{
    struct SegNode
    {
        int l, r;
        ll tag;
    } st[4 * MAXN + 2];

    static inline int lson(int p){return p << 1;}
    static inline int rson(int p){return p << 1 | 1;}

    void build(int p, int l, int r)
    {
        st[p].l = l; st[p].r = r;

        if (l == r)
        {
            st[p].tag = 1;
            return ;
        }

        int mid = (l + r) >> 1;
        build(lson(p), l, mid);
        build(rson(p), mid + 1, r);
        st[p].tag = 0;
    }

    void lazy_down(int p)
    {
        if (st[p].tag)
        {
            st[lson(p)].tag =st[p].tag;
            st[rson(p)].tag =st[p].tag;

            st[p].tag = 0;
        }
    }

    void update(int p, int l, int r, ll k)
    {
        if (st[p].l >= l && st[p].r <= r)
        {
            st[p].tag = k;
            return ;
        }

        lazy_down(p);

        int mid = (st[p].l + st[p].r) >> 1;
        if (mid >= l) update(lson(p), l, r, k);
        if (mid <  r) update(rson(p), l, r, k);
    }

    ll query(int p, int l, int r)
    {
        if (l == r) return st[p].tag;

        lazy_down(p);

        ll ans = 0;
        int mid = (st[p].l + st[p].r) >> 1;
        ans += query(lson(p), l, mid);
        ans += query(rson(p), mid + 1, r);

        return ans;
    }
} st ;

int main()
{
    int _T = read<int>();
    for (int T = 1; T <= _T; T++)
    {
        int n = read<int>(), q = read<int>();
        st.build(1, 1, n);
        for (int i = 0; i < q; i++)
        {
            int x = read<int>(), y = read<int>(), z = read<int>();
            st.update(1, x, y, z);
        }
        printf("Case %d: The total value of the hook is %lld.\n", T, st.query(1, 1, n));
    }
    return 0;
}
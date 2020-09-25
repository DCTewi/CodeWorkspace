#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

const int MAXN = 5e4 + 5;

struct MaxSegTree
{
    struct SegNode
    {
        int l, r;
        ll data, tag;
        SegNode(int l = 0, int r = 0, int d = 0, int t = 0) : l(l), r(r), data(d), tag(t) {}
    };
    static inline int lson(int p){return p << 1;}
    static inline int rson(int p){return p << 1 | 1;}

    vector<SegNode> st;
    int n;

    explicit MaxSegTree(int n, vector<int> raw) : n(n)
    {
        st = vector<SegNode>((n << 2) + 2);
        build(raw, 1, n);
    }

    void push_up(int p)
    {
        st[p].data = max(st[lson(p)].data, st[rson(p)].data);
    }

    void lazy_down(int p)
    {
        if (st[p].tag)
        {
            st[lson(p)].tag += st[p].tag;
            st[rson(p)].tag += st[p].tag;
            st[lson(p)].data += st[p].tag;
            st[rson(p)].data += st[p].tag;
            st[p].tag = 0;
        }
    }

    void build(vector<int> &raw, int l, int r, int p = 1)
    {
        st[p].l = l, st[p].r = r;
        if (l == r)
        {
            st[p].data = ((int)raw.size() >= l)? raw[l - 1]: 0; return;
        }

        int mid = (l + r) >> 1;
        build(raw, l, mid, lson(p));
        build(raw, mid + 1, r, rson(p));

        push_up(p);
    }

    ll query(int l, int r, int p = 1)
    {
        if (st[p].l >= l && st[p].r <= r) return st[p].data;

        lazy_down(p);
        ll ans = 0;
        int mid = (st[p].l + st[p].r) >> 1;
        if (mid >= l) ans = max(ans, query(l, r, lson(p)));
        if (mid <  r) ans = max(ans, query(l, r, rson(p)));

        return ans;
    }
};

struct MinSegTree
{
    struct SegNode
    {
        int l, r;
        ll data, tag;
        SegNode(int l = 0, int r = 0, int d = 0, int t = 0) : l(l), r(r), data(d), tag(t) {}
    };
    static inline int lson(int p){return p << 1;}
    static inline int rson(int p){return p << 1 | 1;}

    vector<SegNode> st;
    int n;

    explicit MinSegTree(int n, vector<int> raw) : n(n)
    {
        st = vector<SegNode>((n << 2) + 2);
        build(raw, 1, n);
    }

    void push_up(int p)
    {
        st[p].data = min(st[lson(p)].data, st[rson(p)].data);
    }

    void lazy_down(int p)
    {
        if (st[p].tag)
        {
            st[lson(p)].tag += st[p].tag;
            st[rson(p)].tag += st[p].tag;
            st[lson(p)].data += st[p].tag;
            st[rson(p)].data += st[p].tag;
            st[p].tag = 0;
        }
    }

    void build(vector<int> &raw, int l, int r, int p = 1)
    {
        st[p].l = l, st[p].r = r;
        if (l == r)
        {
            st[p].data = ((int)raw.size() >= l)? raw[l - 1]: 0; return;
        }

        int mid = (l + r) >> 1;
        build(raw, l, mid, lson(p));
        build(raw, mid + 1, r, rson(p));

        push_up(p);
    }

    ll query(int l, int r, int p = 1)
    {
        if (st[p].l >= l && st[p].r <= r) return st[p].data;

        lazy_down(p);
        ll ans = 1 << 30;
        int mid = (st[p].l + st[p].r) >> 1;
        if (mid >= l) ans = min(ans, query(l, r, lson(p)));
        if (mid <  r) ans = min(ans, query(l, r, rson(p)));

        return ans;
    }
};

int main()
{
    int n = read<int>(), q = read<int>();
    vector<int> cow(n);
    for (int i = 0; i < n; i++)
    {
        cow[i] = read<int>();
    }

    MaxSegTree st1(n, cow);
    MinSegTree st2(n, cow);

    for (int i = 0; i < q; i++)
    {
        int x = read<int>(), y = read<int>();
        printf("%lld\n", st1.query(x, y) - st2.query(x, y));
    }
    return 0;
}

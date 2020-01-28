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
int n;
ll raw_data[MAXN];

struct SegTree
{
    class SegmentTreeNode
    {
    public:
        SegmentTreeNode(){}
        int l, r;
        ll data, maxv;
    } st[4 * MAXN + 2];

    static inline int lson(int p){return p << 1;}
    static inline int rson(int p){return p << 1 | 1;}

    void push_up(int p)
    {
        st[p].data = (st[lson(p)].data + st[rson(p)].data);
        st[p].maxv = max(st[lson(p)].maxv, st[rson(p)].maxv);
    }

    void build(int p, int l, int r)
    {
        st[p].l = l; st[p].r = r;

        if (l == r)
        {
            st[p].data = st[p].maxv = raw_data[l];
            return ;
        }

        int mid = (l + r) >> 1;
        build(lson(p), l, mid);
        build(rson(p), mid + 1, r);

        push_up(p);
    }

    void update(int x, int y, int p = 1)
    {
        if (st[p].maxv <= 1) return;
        if (st[p].l == st[p].r)
        {
            st[p].data = sqrt(st[p].data);
            st[p].maxv = st[p].data;
            return;
        }

        int mid = (st[p].l + st[p].r) >> 1;
        if (x <= mid) update(x, y, lson(p));
        if (y >  mid) update(x, y, rson(p));

        push_up(p);
    }

    long long query(int l, int r, int p = 1)
    {
        if (st[p].l >= l && st[p].r <= r) return st[p].data;

        ll ans = 0;
        int mid = (st[p].l + st[p].r) >> 1;
        if (mid >= l) ans += query(l, r, lson(p));
        if (mid <  r) ans += query(l, r, rson(p));

        return ans;
    }
} st ;

int main()
{
    int _T = 0;
    while (~scanf("%d", &n))
    {
        printf("Case #%d:\n", ++_T);
        for (int i = 1; i <= n; i++)
        {
            raw_data[i] = read<ll>();
        }
        st.build(1, 1, n);
        int q = read<ll>();
        for (int i = 1; i <= q; i++)
        {
            int opt = read<ll>(), x = read<ll>(), y = read<ll>();
            if (!opt)
            {
                st.update(min(x, y), max(x, y));
            }
            else
            {
                printf("%lld\n", st.query(min(x,y), max(x, y)));
            }
        }
        puts("");
    }
    return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10
5
0 1 10
1 1 10
1 1 5
0 5 8
1 4 8

 */
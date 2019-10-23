#pragma GCC optimize(2)
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
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

const int MAXN = 1e5 + 5;
const int UPLIMIT = 1e7 + 5;

struct Node
{
    ll l, r;
} dat[MAXN] ;
int lis[MAXN], vis[MAXN], ans = 0;

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
            st[p].tag = 0;
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

    void query(int p, int l, int r)
    {
        if (st[p].tag && !vis[st[p].tag])
        {
            vis[st[p].tag] = 1;
            ans++;
            return;
        }

        if (l == r) return;

        lazy_down(p);

        int mid = (st[p].l + st[p].r) >> 1;
        query(lson(p), l, mid);
        query(rson(p), mid + 1, r);
    }
} st ;

void init()
{
    memset(vis, 0, sizeof(vis));
    memset(lis, 0, sizeof(lis));
    memset(st.st, 0, sizeof(st.st));
    ans = 0;
}

int main()
{
    int T = read<int>();
    while (T--)
    {
        init();
        int n = read<int>(), cnt = 0, end = 0;
        for (int i = 1; i <= n; i++)
        {
            dat[i].l = read<int>();
            dat[i].r = read<int>();
            lis[cnt++] = dat[i].l;
            lis[cnt++] = dat[i].r;
        }
        sort(lis, lis + cnt);

        cnt = end = unique(lis, lis + cnt) - lis;
        for (int i = 1; i < end; i++)
        {
            if (lis[i] - lis[i - 1] > 1) lis[cnt++] = lis[i - 1] + 1;
        }
        sort(lis, lis + cnt);

        st.build(1, 1, cnt);
        for (int i = 1; i <= n; i++)
        {
            int x = lower_bound(lis, lis + cnt, dat[i].l) - lis + 1;
            int y = lower_bound(lis, lis + cnt, dat[i].r) - lis + 1;
            // printf("x = %d, y = %d\n", x, y);
            st.update(1, x, y, i);
        }

        st.query(1, 1, cnt);

        printf("%d\n", ans);
    }
    return 0;
}

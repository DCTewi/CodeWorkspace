#include <bits/stdc++.h>
using namespace std;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

const int MAXN = 1e5 + 5;
const int MOD = 1e4 + 7;

struct Tree
{
    int st[MAXN << 2];

    void pushdown(int rt)
    {
        if (st[rt] == -1) return;
        st[rt << 1] = st[rt << 1 | 1] = st[rt];
        st[rt] = -1;
    }

    void pushup(int opt, int c, int l, int r, int rt)
    {
        if (st[rt] >= 0)
        {
            if (opt == 1) st[rt] = (st[rt] + c) % MOD;
            else st[rt] = st[rt] * c % MOD;
            return;
        }
        pushup(opt, c, l, (l + r) / 2, rt << 1);
        pushup(opt, c, (l + r) / 2 + 1, r, rt << 1 | 1);
    }

    void update(int opt, int x, int y, int c, int l, int r, int rt)
    {
        if (r < x || l > y) return;
        if (x <= l && r <= y)
        {
            if (opt == 3) st[rt] = c;
            else pushup(opt, c, l, r, rt);
            return;
        }
        pushdown(rt);

        update(opt, x, y, c, l, (l + r) / 2, rt << 1);
        update(opt, x, y, c, (l + r) / 2 + 1, r, rt << 1 | 1);
    }

    int query(int x, int y, int p, int l, int r, int rt)
    {
        if (r < x || l > y) return 0;
        if (st[rt] >= 0)
        {
            int res = min(y, r) - max(x, l) + 1;
            for (int i = 1; i <= p; i++)
            {
                res = res * st[rt] % MOD;
            }
            return res;
        } 
        return (query(x, y, p, l, (l + r) / 2, rt << 1) + query(x, y, p, (l + r) / 2 + 1, r, rt << 1 | 1)) % MOD;
    }
} st;

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m), n || m)
    {
        st.st[1] = 0;
        while (m--)
        {
            int opt = read<int>(), x = read<int>(), y = read<int>(), c = read<int>();
            if (opt == 4) printf("%d\n", st.query(x, y, c, 1, n, 1));
            else st.update(opt, x, y, c, 1, n, 1);
        }
    }
    return 0;
}

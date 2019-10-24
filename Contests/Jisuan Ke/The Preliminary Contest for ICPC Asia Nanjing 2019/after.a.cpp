#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;

struct Node
{
    int x, y;
    int mark, id;

    bool operator< (const Node &o) const
    {
        return (x != o.x)? x < o.x:
            (y != o.y)? y < o.y:
            mark > o.mark;
    }
} tile[MAXN] ;
int num;
void addtile(int X, int Y, int M, int I)
{
    num++;
    tile[num].x = X;
    tile[num].y = Y;
    tile[num].mark = M;
    tile[num].id = I;
}

ll c[MAXN], top;
inline int lowbit(int x)
{
    return x & (-x);
}
void add(int pos, int val)
{
    while (pos <= top)
    {
        c[pos] += val;
        pos += lowbit(pos);
    }
}
ll query(int pos)
{
    ll res = 0;
    while (pos > 0)
    {
        res += c[pos];
        pos -= lowbit(pos);
    }
    return res;
}

int getxy(int x, int y, int len)
{
    int wid = min(min(x - 1, y - 1), min(len - x, len - y));
    ll val = 2ll * (2 * len - 2 - 2 * (wid - 1)) * wid;
    len -= wid * 2;
    x -= wid; y -= wid;

    if (x == len && y > 1) val += (len - y + 1);
    else if (y == 1 && x > 1) val += (len - 1 + len - x + 1);
    else if (x == 1 && y < len) val += (2 * (len - 1) + y);
    else val += (3 * (len - 1) + x);
    
    int res = 0;
    while (val)
    {
        res += val % 10;
        val /= 10;
    }
    return res;
}

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

int n, m, q;
ll ans[MAXN];

int main()
{
    int T = read<int>();
    while (T--)
    {
        n = read<int>(), m = read<int>(), q = read<int>();

        for (int i = 0; i <= n; i++) c[i] = 0;
        top = n;
        num = 0;

        for (int i = 1; i <= m; i++)
        {
            int a = read<int>(), b = read<int>();
            addtile(a, b, 2, getxy(a, b, n));
        }

        for (int i = 1; i <= q; i++)
        {
            int a = read<int>(), b = read<int>(), c = read<int>(), d = read<int>();            
            addtile(c, d, 1, i);
            addtile(a - 1, b - 1, 1, i);
            addtile(a - 1, d, -1, i);
            addtile(c, b - 1, -1, i);
            ans[i] = 0;
        }

        sort(tile + 1, tile + 1 + num);

        for (int i = 1; i <= num; i++)
        {
            if (tile[i].mark == 2) add(tile[i].y, tile[i].id);
            else
            {
                ans[tile[i].id] += query(tile[i].y) * tile[i].mark;
            }
        }
        for (int i = 1; i <= q; i++)
        {
            printf("%I64d\n", ans[i]);
        }
    }
    return 0;
}


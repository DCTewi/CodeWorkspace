#include <bits/stdc++.h>
using namespace std;

const int N = 1500;
const int inf = 1e8;

int n, q, mx[N][N], mi[N][N];
int fg, xo, mians, mxans;

int read()
{
    int x = 0, w = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar(), w |= ch == '-';
    while (isdigit(ch))
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return w? -x: x;
}

void upd2(int l, int r, int o, int y, int v)
{
    if (l == r)
    { ///如果找到了二维下标
        if (fg)
            mi[xo][o] = v, mx[xo][o] = v; ///如果此时正好找到了一维下标，就赋值
        else
        { ///否则更新一维的情况
            mi[xo][o] = min(mi[2 * xo][o], mi[2 * xo + 1][o]);
            mx[xo][o] = max(mx[2 * xo][o], mx[2 * xo + 1][o]);
        }
        return;
    }
    int m = (l + r) / 2;
    if (y <= m)
        upd2(l, m, 2 * o, y, v);
    else
        upd2(m + 1, r, 2 * o + 1, y, v);
    mi[xo][o] = min(mi[xo][2 * o], mi[xo][2 * o + 1]); ///递归回来更新二维情况
    mx[xo][o] = max(mx[xo][2 * o], mx[xo][2 * o + 1]);
}

///更新一维，x为要更新的一维下标，y为要更新的二维下标
void upd1(int l, int r, int o, int x, int y, int v)
{
    if (l == r)
    {
        fg = 1; ///打上标记
        xo = o;
        upd2(1, n, 1, y, v);
        return;
    }
    int m = (l + r) / 2;
    if (x <= m)
        upd1(l, m, 2 * o, x, y, v);
    else
        upd1(m + 1, r, 2 * o + 1, x, y, v);
    fg = 0, xo = o;
    upd2(1, n, 1, y, v);
}

void qy2(int l, int r, int o, int pre, int ly, int ry)
{
    if (ly <= l && ry >= r)
    {
        mians = min(mians, mi[pre][o]);
        mxans = max(mxans, mx[pre][o]);
        return;
    }
    int m = (l + r) / 2;
    if (ly <= m)
        qy2(l, m, 2 * o, pre, ly, ry);
    if (ry > m)
        qy2(m + 1, r, 2 * o + 1, pre, ly, ry);
}

void qy1(int l, int r, int o, int lx, int rx, int ly, int ry)
{
    if (lx <= l && rx >= r)
    {
        qy2(1, n, 1, o, ly, ry);
        return;
    }
    int m = (l + r) / 2;
    if (lx <= m)
        qy1(l, m, 2 * o, lx, rx, ly, ry);
    if (rx > m)
        qy1(m + 1, r, 2 * o + 1, lx, rx, ly, ry);
}

void init()
{
    memset(mx, 0, sizeof(mx));
    memset(mi, 0, sizeof(mi));
    fg = 0, xo = 0;
    n = read();
    int v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1;j <= n; j++)
        {
            v = read(), upd1(1, n, 1, i, j, v);
        }
    }
}

int query(int x, int y, int x1, int y1)
{
    mians = inf;
    mxans = 0;
    qy1(1, n, 1, x, x1, y, y1);
    return mxans - mians;
}

void add(int x, int y, int v)
{
    upd1(1, n, 1, x, y, v);
}

void solve()
{
    
}

int main()
{

    return 0;
}

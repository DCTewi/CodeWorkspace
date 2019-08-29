#include <bits/stdc++.h>
using namespace std;
typedef __int128_t ll;

const int MAXN = 1e5 + 5;

int n, q;

template <typename ty> void print(ty x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template <typename ty> ty read()
{
    ty x = 0; int w = 0; char ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

struct SegTree
{
    ll st[MAXN << 2], add[MAXN << 2];
    int N = 1;

    inline void build(vector<ll> &raw)
    {
        for (; N < n + 1; N <<= 1); // Get raw data's place.5
        for (int i = N + 1; i <= N + n; i++) st[i] = raw[i - N]; // Raw data.
        for (int i = N - 1; i >= 1; i--) st[i] = st[i << 1] + st[i << 1 | 1]; // Build from leaves.
    }

    inline void update(int l, int r, ll k)
    {
        int s = N + l - 1, t = N + r + 1; // Left and Right.
        ll lNum = 0, rNum = 0, num = 1; // how many k left contained = lNum, how many k this plate contained = num.
        for (; s ^ t ^ 1; s >>= 1, t >>= 1, num <<= 1) // If s and t has same father, s ^ t == 1, 1 ^ 1 == 0
        {
            st[s] += k * lNum;
            st[t] += k * rNum;
            if (~s & 1) {add[s ^ 1] += k; st[s ^ 1] += k * num; lNum += num;} // If s is the left kid of its father, add its brother node.
            if ( t & 1) {add[t ^ 1] += k; st[t ^ 1] += k * num; rNum += num;} // If t is the right kid of its father, add its brother node.
        }
        for (; s; s >>= 1, t >>= 1) // Up to root
        {
            st[s] += k * lNum;
            st[t] += k * rNum;
        }
    }

    inline ll query(int l, int r)
    {
        int s = N + l - 1, t = N + r + 1; // Left and Right.
        ll lNum = 0, rNum = 0, num = 1, ans = 0; // Same as update()#lNum.
        for (; s ^ t ^ 1; s >>= 1, t >>= 1, num <<= 1)
        {
            if (add[s]) ans += add[s] * lNum; // Add the add lazy tag.
            if (add[t]) ans += add[t] * rNum;
            if (~s & 1) {ans += st[s ^ 1]; lNum += num;}
            if ( t & 1) {ans += st[t ^ 1]; rNum += num;}
        }
        for (; s; s >>= 1, t >>= 1) // Up to root
        {
            ans += add[s] * lNum;
            ans += add[t] * rNum;
        }
        return ans;
    }

} sum, mul ; 

int main()
{
    n = read<int>(), q = read<int>();
    vector<ll> raw(n + 1), mid(n + 1);
    for (int i = 1; i <= n; i++)
    {
        raw[i] = read<ll>();
        mid[i] = raw[i] * (n - i + 1);
    }

    sum.build(raw);
    mul.build(mid);

    for (int Q = 0; Q < q; Q++)
    {
        int opt = read<int>(), x = read<int>(), y = read<int>();
        switch (opt)
        {
        case 1:
            print(mul.query(x, y) - sum.query(x, y) * (n - y)); puts("");
            break;
        
        case 2:
            ll delta = y - raw[x];
            raw[x] = y;
            sum.update(x, x, delta);
            mul.update(x, x, delta * (n - x + 1));
            break;
        }
    }
    return 0;
}

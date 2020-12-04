#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;

}

const int MAXN = 5e4 + 5;

struct BIT
{
    int c[MAXN], n = 0;

    BIT(int n) : n(n)
    {
        memset(c, 0, sizeof(c));
    }

    static inline int lowbit(int p)
    {
        return p & (-p);
    }

    void add(int p, int delta)
    {
        for (; p <= n; p += lowbit(p))
        {
            c[p] += delta;
        }
    }

    int sumall(int p)
    {
        int ans = 0;
        for (; p > 0; p -= lowbit(p))
        {
            ans += c[p];
        }
        return ans;
    }

    int sum(int l, int r)
    {
        return sumall(r) - sumall(l - 1);
    }
};

int main()
{
    int T = read<int>();
    for (int _t = 1; _t <= T; _t++)
    {
        printf("Case %d:\n", _t);
        int n = read<int>();
        BIT bit(n);

        for (int i = 1; i <= n; i++)
        {
            bit.add(i, read<int>());
        }

        string opt;
        while (opt != "End")
        {
            cin >> opt;
            if (opt[0] == 'A')
            {
                int x = read<int>(), y = read<int>();
                bit.add(x, y);
            }
            else if (opt[0] == 'S')
            {
                int x = read<int>(), y = read<int>();
                bit.add(x, -y);
            }
            else if (opt[0] == 'Q')
            {
                int x = read<int>(), y = read<int>();
                printf("%lld\n", bit.sum(x, y));
            }
        }
    }
    return 0;
}
/*
2
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End

 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

int main()
{
    int T = read<int>();
    while (T--)
    {
        int n = read<int>();
        vector<int> a(n + 1); a[0] = 0;
        int p1 = 0, p2 = 0;
        for (int i = 1; i <= n; i++)
        {
            a[i] = read<int>();
            if (!p1 && a[i] < i - 1) p1 = i - 1;
        }
        if (!p1) p1 = n;
        for (int i = n; i > 0; i--)
        {
            if (a[i] < (n - i))
            {
                p2 = i + 1; break;
            }
        }
        if (!p2) p2 = 1;
        puts(p2 > p1? "No" : "Yes");
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T>
T read()
{
    T x = 0;
    int ch = getchar(), w = 0;
    while (!isdigit(ch))
        w |= ch == '-', ch = getchar();
    while (isdigit(ch))
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

int f(int m, int n)
{
    if (m <= 1 || n == 1) return 1;
    else if (n == 0) return 0;
    else if (n > m) return f(m, n - 1);
    return f(m - n, n) + f(m, n - 1);
}

int main()
{
    int T = read<int>();
    while (T--)
    {
        int m = read<int>(), n = read<int>();
        printf("%d\n", f(m, n));
    }
    return 0;
}
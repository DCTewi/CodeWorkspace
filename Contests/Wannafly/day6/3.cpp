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

int main()
{
    int n = read<int>();
    vector<int> a(n);

    for (int i = 1; i <= n / 2; i++)
    {
        a[i - 1] = (i << 1) - 1;
    }
    for (int i = 1; i <= n / 2; i++)
    {
        a[n - i] = (i << 1);
    }
    if (n & 1)
    {
        a[n >> 1] = n;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
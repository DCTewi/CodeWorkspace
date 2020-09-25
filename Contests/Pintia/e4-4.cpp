#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> T read()
{
    T x = 0; int ch = getchar(), w = 0;
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

const int MAXN = 1e4 + 5;
int a[MAXN], ans = 0;

int main()
{
    int n = read<int>();

    for (int i = 0; i < n; i++)
    {
        a[i] = read<int>();
    }
    int now = 0;
    for (int i = 0; i < n; i++)
    {
        now = (now + a[i] > a[i]) ? now + a[i] : a[i];
        if (now > ans) ans = now;
    }

    printf("%d\n", ans);

    return 0;
}
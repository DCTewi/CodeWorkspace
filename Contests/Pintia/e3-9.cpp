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
const int MAXN = 1e3 + 5;

ll ans = 0;
int a[MAXN], swp[MAXN];

void merge(const int &l, const int &r, const int &mid)
{
    int i = l, j = mid + 1, k = l;

    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j]) swp[k++] = a[i++];
        else swp[k++] = a[j++], ans += (mid - i + 1);
    }
    while (i <= mid) swp[k++] = a[i++];
    while (j <= r  ) swp[k++] = a[j++];
    for (int i = l; i <= r; i++) a[i] = swp[i];
}

void merge(const int &l, const int &r)
{
    if (l < r)
    {
        int mid = (l + r) >> 1;
        merge(l, mid);
        merge(mid + 1, r);
        merge(l, r, mid);
    }
}

int main()
{
    int n = read<int>();
    for (int i = 0; i < n; i++) a[i] = read<int>();

    ans = 0;
    merge(0, n - 1);

    printf("%lld\n", ans);

    return 0;
}

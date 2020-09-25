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

const int MAXN = 2e5 + 5;
int a[MAXN], dp[MAXN];

int main()
{
    int n = read<int>();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read<int>();;
    }
    int ans = 1;
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        int l = 1, r = ans;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (a[i] <= dp[mid]) r = mid - 1;
            else l = mid + 1;
        }
        dp[l] = a[i];
        ans += (l > ans);
    }

    printf("%d\n", ans);
    return 0;
}

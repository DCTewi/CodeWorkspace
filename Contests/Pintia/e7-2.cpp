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

const ll MOD = 2147483648;
const ll MAXN = 4e4 + 5;

ll dp[MAXN];

int main()
{
    int T = read<int>();
    while (T--)
    {
        int n = read<int>();
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = i; j <= n; j++)
            {
                dp[j] = (dp[j] + dp[j - i]) % MOD;
            }
        }
        printf("%lld\n", dp[n]);
    }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        ll n, m, k;
        scanf("%lld%lld%lld", &n, &m, &k);
        printf("%lld\n", k * (m + 1));
    }
    return 0;
}

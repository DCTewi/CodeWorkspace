#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int read()
{
    int x = 0, ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    int T = read();
    for (int t = 1; t <= T; t++)
    {
        int n = read(), b = read();
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int nn = i;
            while (nn)
            {
                ans += nn % b;
                nn /= b;
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}

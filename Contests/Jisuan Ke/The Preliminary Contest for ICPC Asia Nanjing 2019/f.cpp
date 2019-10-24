#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n, k;
map<int, int> plc;

template <class T>
T read()
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
        n = read<int>(), k = read<int>();
        vector<int> dp(n + 1, 1);

        for (int i = 0; i < n; i++)
        {
            int u = read<int>();
            plc[u] = i;
        }

        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {            
            for (int j = i - 1; j > 0; j--)
            {
                int len = abs(plc[j] - plc[i]);
                if (len > k) continue;

                dp[i] = dp[j] + 1; break;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            printf("%d%c", dp[i], " \n"[i == n]);
        }
    }
}

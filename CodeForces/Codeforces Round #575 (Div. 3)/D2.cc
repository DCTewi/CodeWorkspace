#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
const string T = "RGB";
int c1[MAXN];
int c2[MAXN];
int c3[MAXN];
int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        string s;
        cin >> s;
        for (int i = 0; i <= n; i++)
            c1[i] = c2[i] = c3[i] = 0;
        int now1 = 0, now2 = 1, now3 = 2;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == T[now1])
            {
                c1[i + 1] = 1;
            }
            if (s[i] == T[now2])
            {
                c2[i + 1] = 1;
            }
            if (s[i] == T[now3])
            {
                c3[i + 1] = 1;
            }
            now1++; now2++; now3++;
            now1 %= 3; now2 %= 3; now3 %= 3;
        }
        for (int i = 1; i <= n; i++)
            c1[i] += c1[i - 1], c2[i] += c2[i - 1], c3[i] += c3[i - 1];
        int ans = 1e9;
        for (int i = 1; i <= n - k + 1; i++)
        {
            ans = min(ans, k - (c1[i + k - 1] - c1[i - 1]));
            ans = min(ans, k - (c2[i + k - 1] - c2[i - 1]));
            ans = min(ans, k - (c3[i + k - 1] - c3[i - 1]));
        }

        printf("%d\n", ans);
        for (int i = 0; i <= n; i++)
            c1[i] = c2[i] = c3[i] = 0;
    }
    return 0;
}

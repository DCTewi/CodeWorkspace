#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string T = "RGB";
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
        string t1, t2, t3;
        int now1 = 0, now2 = 1, now3 = 2;
        for (int i = 0; i < k; i++)
        {
            t1 += T[now1];
            t2 += T[now2];
            t3 += T[now3];
            now1++; now2++; now3++;
            now1 %= 3; now2 %= 3; now3 %= 3;
        }
        int tmp = 1e9;
        for (int i = 0; i <= s.size() - k; i++)
        {
            int tot1 = 0, tot2 = 0, tot3 = 0;
            for (int j = 0; j < k; j++)
            {
                tot1 += (s[i + j] != t1[j]);
                tot2 += (s[i + j] != t2[j]);
                tot3 += (s[i + j] != t3[j]);
            }
            tmp = min(tmp, min(tot1, min(tot2, tot3)));
        }
        printf("%d\n", tmp);
    }
    return 0;
}

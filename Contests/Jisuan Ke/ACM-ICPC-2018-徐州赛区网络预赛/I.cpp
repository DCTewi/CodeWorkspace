#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
    {
        int len; cin >> len;
        char seed; cin >> seed;
        string s; cin >> s;

        int ans = 0, num = 0;
        while (s[num] == seed) num++;
        if (abs(s[num] - seed) < 10) ans = -1;

        // for (int i = 0; i < len; i++)
        // {
        //     printf("%c : %d\n", s[i], abs(s[i] - seed));
        // }

        ans += len * 2 - num * 2;

        printf("%d\n", ans? ans: 1);
    }
    return 0;
}

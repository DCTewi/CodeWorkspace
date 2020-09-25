#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        int flag = 0;
        for (int i = 1; i < n; i++)
        {
            if (flag) break;
            if (a[i] == a[i - 1])
            {
                puts("NO");
                flag = 1;
            }
        }
        if (!flag) puts("YES");
    }
    return 0;
}

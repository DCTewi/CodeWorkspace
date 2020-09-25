// F - K-hour-clock  [WA]
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x + y == z)
        {
            printf("%d\n", z + 1);
        }
        else if ((z > x && z - x > y) || (z < x && y - z < 0))
        {
            puts("-1");
        }
        else
        {
            if (x > z) printf("%d\n", x + (y - z));
            else
            {
                int k = y - abs(z - x);
                if (k < abs(z - x)) puts("-1");
                else printf("%d\n", k);
            }
        }
    }
    return 0;
}
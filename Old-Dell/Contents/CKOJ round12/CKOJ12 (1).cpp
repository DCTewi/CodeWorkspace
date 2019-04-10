#include <bits/stdc++.h>
using namespace std;

int main()
{
    char times[6];
    scanf("%s", times);
    int x,y;
    x = (int)(times[0] - '0') * 10 + (int)(times[1] - '0');
    y = (int)(times[3] - '0') * 10 + (int)(times[4] - '0');

    if (x < 0 || y < 0)
    {
        printf("-1");
    }
    else if(x >= 24 || y >= 60)
    {
        printf("-1");
    }
    else
    {
        int mins = x * 60 + y;
        int ans = 60 * 24 - mins;
        printf("%d\n", ans);
    }

    return 0;
}

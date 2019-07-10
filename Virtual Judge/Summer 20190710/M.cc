// M - Sekiro 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // ios::sync_with_stdio(0);
    int T; scanf("%d", &T);
    while (T--)
    {
        ll left, die;
        scanf("%lld%lld", &left, &die);

        if (!left) puts("0");
        else if (die > 31) puts("1");
        else
        {
            for (int i = 0; i < die; i++)
            {
                if (left & 1) left++;
                left /= 2;
            }
            printf("%lld\n", left);
        }
    }

}
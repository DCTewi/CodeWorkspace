#include <cstdio>

using namespace std;

int main()
{
    int t;scanf("%d", &t);
    while (t--)
    {
        int n;scanf("%d", &n);
        long long int ans = 1;
        for (int i = 0; i < n; i++)
        {
            long long int tmp; scanf("%lld", &tmp);
            ans *= tmp;
        }

        long long int B; scanf("%lld", &B);
        if (ans == B)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}

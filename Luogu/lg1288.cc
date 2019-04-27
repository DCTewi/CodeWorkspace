#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e2 + 5;
int n;
int a[MAXN];

int main()
{
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (!a[i])
        {
            if (!(i & 1))
            {
                return 0 * puts("YES");
            }
            break;
        }
    }

    for (int i = n; i >= 1; i--)
    {
        if (!a[i])
        {
            if (!((n - i + 1) & 1))
            {
                return 0 * puts("YES");
            }
            break;
        }
    }

    puts("NO");

    return 0;
}
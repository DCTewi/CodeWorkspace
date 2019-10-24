#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;

int n, m;
int a[MAXN], b[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    sort(a, a + n); sort(b, b + m);

    printf("%d %d\n", a[n - 1], b[m - 1]);

    return 0;
}


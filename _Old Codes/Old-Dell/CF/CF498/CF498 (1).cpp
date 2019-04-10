#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", (a[i] & 1)? a[i]: a[i] - 1);
    }
    printf("\n");

    return 0;
}

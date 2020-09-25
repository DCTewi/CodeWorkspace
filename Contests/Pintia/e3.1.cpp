#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    if (n == 1) puts("0");
    else printf("%d\n", (n - 1) / (k - 1) + ((n - 1) % (k - 1) != 0));

    return 0;
}
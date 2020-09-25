#include <cstdio>
#include <iostream>

using namespace std;
int a, b, c, n;

int main()
{
    scanf("%d%d%d%d", &a, &b, &c, &n);
    if (a + b - c >= n || a < c || b < c)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", n - a - b + c);
    }

    return 0;
}

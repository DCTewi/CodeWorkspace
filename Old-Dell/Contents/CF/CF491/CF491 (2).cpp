#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, times = 0;
double gra[105];

double getGrad()
{
    double tot = 0;
    for (int i = 0; i < n; i++)
    {
        tot += gra[i];
    }
    return tot / (double)n;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &gra[i]);
    }
    sort(gra, gra + n);

    while (getGrad() < 4.5)
    {
        gra[times++] = 5.0;
    }

    printf("%d\n", times);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long double lb;
const int EXP = 1e6;

lb sum;

int main()
{
    lb tmp;
    while (scanf("%Lf", &tmp) != EOF)
    {
        sum += tmp * EXP;
    }
    printf("%.5Lf\n", sum / EXP);
    return 0;
}

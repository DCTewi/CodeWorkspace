#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 5e3 + 5;
int n, k;
double ans = 0.0, sum[MAX], a[MAX];

int main()
{
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if (!i)
        {
            sum[i] = a[i];
        }
        else sum[i] = sum[i - 1] + a[i];
    }

    for (int nk = k; nk <= n; nk++)
    {
        for (int i = 0; i < n - nk; i++)
        {
            double aver = (sum[i + nk] - (i? sum[i - 1]: 0)) / nk;
            if (aver > ans)
            {
                ans = aver;
            }
        }
    }

    printf("%.10lf\n", ans);

    return 0;
}

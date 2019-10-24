/*
    Result: __gcd() is better than inline oneline gcd()
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXL = 2e6 + 5;

int a[MAXL];

inline int gcd(int a, int b)
{
    return b? gcd(b, a % b): a;
}

int main()
{   
    srand(time(0));
    for (int t = 0; t < 10; t++)
    {
        for (int i = 0; i < MAXL; i++)
        {
            a[i] = rand();
        }

        clock_t start, end;
        start = clock();
        for (int i = 0; i < MAXL - 1; i++)
        {
            __gcd(a[i], a[i + 1]);
        }
        end = clock();
        cout<<"cpp gcd used "<<(double)(end - start) / CLOCKS_PER_SEC<<" secs\n";

        start = clock();
        for (int i = 0; i < MAXL - 1; i++)
        {
            gcd(a[i], a[i + 1]);
        }
        end = clock();
        cout<<"oneline gcd used "<<(double)(end - start) / CLOCKS_PER_SEC<<" secs\n\n";
    }

    return 0;
}

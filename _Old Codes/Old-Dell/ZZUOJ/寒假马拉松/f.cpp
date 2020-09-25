#include <bits/stdc++.h>
using namespace std;

const int che = 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9;
n
inline int spe(int x)
{
    return (x / 100) * (x % 100 / 10) * (x % 10);
}

inline bool check(int x)
{
    if ( spe(x) * spe(2 * x) * spe(3 * x) == che) return true;
    return false;
}

int main()
{
    for (int i=123;i<333;i++)
    {
        if (check(i)) printf("%d %d %d\n", i, 2 * i, 3 * i);
    }
    return 0;
}


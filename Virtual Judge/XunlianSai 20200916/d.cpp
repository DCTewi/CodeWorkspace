#include <bits/stdc++.h>
using namespace std;

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    int T = read<int>();
    while (T--)
    {
        int n = read<int>();

        if (n == 1)
        {
            puts("26");
        }
        else if (n == 2)
        {
            puts("676");
        }
        else if (n == 3)
        {
            puts("17576");
        }
        else
        {
            puts("15600");
        }
    }
    return 0;
}

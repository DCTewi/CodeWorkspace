#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> T read()
{
    T x = 0; int ch = getchar(), w = 0;
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

int main()
{
    int T = read<int>();
    while (T--)
    {
        int x = read<int>(), y = read<int>();
        int a = read<int>(), b = read<int>();
        int len = y - x, step = a + b;
        if (len % step != 0)
        {
            puts("-1");
        }
        else 
        {
            printf("%d\n", len / step);
        }
    }
    return 0;
}

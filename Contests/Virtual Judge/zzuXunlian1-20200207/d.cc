#include <bits/stdc++.h>
using namespace std;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;    
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        if (n == 0) return 0;

        
    }
    return 0;
}
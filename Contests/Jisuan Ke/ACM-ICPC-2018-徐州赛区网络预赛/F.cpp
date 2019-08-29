#include <bits/stdc++.h>
using namespace std;

template <typename ty> ty read()
{
    ty x = 0; int w = 0; char ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

int main()
{
    int T = read<int>();
    while (T--)
    {
        int n = read<int>(),
            k = read<int>();
        for (int i = 0; i < k; i++)
        {
            
        }
    }
    return 0;
}
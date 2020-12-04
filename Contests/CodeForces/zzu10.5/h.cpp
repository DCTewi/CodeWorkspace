#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{
    int v = read<int>(), n = read<int>();

    int tot = v * n;

    for (int i = 1; i <= 9; i++)
    {
        int now = tot * i % 10? tot * i / 10 + 1: tot * i / 10;
        printf("%d%c", now, " \n"[i == 9]);
    }

    return 0;
}


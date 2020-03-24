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

const int MAXN = 1e4 + 5;
int n;
int pos[MAXN], len = 0;

int main()
{
    n = read<int>();
    for (int i = 0; i < n; i++)
    {
        read<int>();
        pos[i] = read<int>();
    }
    sort(pos, pos + n);
    int midy = pos[(n) / 2];

    for (int i = 0; i < n; i++)
    {
        len += abs(pos[i] - midy);
    }

    printf("%d\n", len);
    return 0;
}

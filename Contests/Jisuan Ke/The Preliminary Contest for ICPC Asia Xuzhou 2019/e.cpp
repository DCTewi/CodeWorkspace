#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> T read()
{
    T x = 0; int w = 0, ch = getchar();
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w? -x: x;
}

const int MAXN = 5e5 + 5;

map<int, int> plc;

int main()
{
    n = read<int>(); int m = read<int>();
    vector<ll> w(n + 1);

    w[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        w[i] = read<ll>();
        plc[w[i] - m]
    }


    return 0;
}

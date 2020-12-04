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
        ll n = read<int>(), m = read<int>();
        ll all = ((n + 1) * n) / 2;

        ll x = n - m, y = m + 1;

        ll plus = x % y;
        ll per = x / y;
        //printf("x:%d, y:%d, plus:%d, per:%d - ", x, y, plus, per);
        
        ll a = y - plus, &b = plus;
        ll neg = ((per + 1) * per) / 2 * a + ((per + 2) * (per + 1)) / 2 * b;
        //cout << a << " " << b << "\n";

        printf("%lld\n", all - neg);
    }
}
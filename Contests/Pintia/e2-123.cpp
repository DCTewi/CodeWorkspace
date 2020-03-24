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

const int FACT = 2;
const ll MOD = 998244353;

struct Matrix
{
    ll dat[FACT][FACT];

    Matrix()
    {
        memset(dat, 0, sizeof dat);
    }
    
    void init()
    {
        for (int i = 0; i < FACT; i++) dat[i][i] = 1;
    }

    Matrix operator*(const Matrix &o) const
    {
        Matrix res;
        for (int i = 0; i < FACT; i++)
        {
            for (int j = 0; j < FACT; j++)
            {
                res.dat[i][j] = 0;
                for (int k = 0; k < FACT; k++)
                {
                    res.dat[i][j] += this->dat[i][k] * o.dat[k][j];
                    res.dat[i][j] %= MOD;
                }
            }
        }
        return res;
    }

    friend Matrix operator^(Matrix base, ll n)
    {
        Matrix res;
        res.init();
        while (n)
        {
            if (n & 1) res = res * base;
            base = base * base;
            n >>= 1;
        }
        return res;
    }
};

int main()
{
    ll n = read<ll>();
    if (n == 1 || n == 2) return 0 * puts("1");

    Matrix ans;
    ans.dat[0][0] = ans.dat[0][1] = ans.dat[1][0] = 1;
    ans = ans ^ n;

    printf("%lld\n", ans.dat[0][1]);
    return 0;
}

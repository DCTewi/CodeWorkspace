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

const int MAXN = 3e3 + 5;

char tile[MAXN][MAXN];

ll q_pow(ll a, ll k)
{
	if (!k) return 1;

	ll ans = 1;
	while (k)
	{
		if (k & 1) ans = ans * a;
		a = a * a;
		k >>= 1;
	}
	return ans;
}

void gen(int n, int x, int y)
{
    if (n == 1)
    {
        tile[x][y] = 'X'; return;
    }

    int size = q_pow(3, n - 2);
    gen(n - 1, x, y);
    gen(n - 1, x, y + 2 * size);
    gen(n - 1, x + 2 * size, y);
    gen(n - 1, x + size, y + size);
    gen(n - 1, x + 2 * size, y + 2 * size);
}

int main()
{
    int t; 
    while (~scanf("%d", &t))
    {
        if (t == -1) return 0;

        memset(tile, ' ', sizeof tile);

        int wid = q_pow(3, t - 1);
        gen(t, 0, 0);

        for (int i = 0; i < wid; i++)
        {
            tile[i][wid] = '\0';
            printf("%s\n", tile[i]);
        }
        puts("-");
    }
    return 0;
}

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

const int MAXM = 1e4 + 5;
const int MAXN = 1e1 + 5;
const int TIMES = 20; //Test times;

ll q_exp(ll a, ll k, ll mod)
{
	if (!k) return 1;

	ll ans = 1;
	while (k)
	{
		if (k & 1) ans = ans * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return ans;
}

inline ll q_mul(ll a, ll b, ll mod)
{
	return a * b % mod;
}

ll random(ll n)
{
	return ((double)rand() / RAND_MAX * n + 0.5);
}

bool witness(ll a, ll n) //Check witness
{
	ll tem = n - 1;
	int j = 0;
	while (!(tem & 1))
	{
		tem /= 2;
		j++;
	}
	// n - 1 => a ^ r * s
	ll x = q_exp(a, tem, n);
	if (x == 1 || x == n - 1) return true;

	while (j--)
	{
		x = q_mul(x, x, n);
		if (x == n - 1) return true;
	}
	return false;
}

bool miller_rabin(ll p) //Generate random a to check if there is a witness of p.
{
	if (p == 2) return true;
	if (p < 2 || !(p & 1)) return false;

	for (int i = 1; i < TIMES; i++)
	{
		ll a = random(p - 2) + 1;
		if (!witness(a, p))
		{
			return false;
		}
	}

	return true;
}

ll gcd(ll a, ll b)
{
    return b == 0? a: gcd(b, a % b);
}

ll factor[MAXM], total;

ll pollard_rho(ll n, ll c)
{
	ll x, y, d, i = 1, k = 2;
	x = rand() % n;
	y = x;
	while (1)
	{
		i++;
		x = (q_mul(x, x, n) + c) % n;
		d = gcd(y - x, n);
		if (d < 0) d = -d;
		if (d > 1 && d < n) return d;
		if (y == x) return n;
		if (i == k)
		{
			y = x;
			k <<= 1;
		}
	}
}

void findp(ll n)
{
	if (miller_rabin(n))
	{
		factor[++total] = n;return;
	}
	ll p = n;
	while (p >= n)
	{
		p = pollard_rho(p, rand() % (n - 1) + 1);
	}
	findp(n / p);
	findp(p);
}

int n, a[MAXN];

int main()
{
	int T = read<int>();
	while (T--)
	{
		n = read<int>();
		for (int i = 0; i < n; i++)
		{
			a[i] = read<int>();
		}

		for (int i = 0; i < n; i++)
		{
			total = 0;
			findp(n);

			for (int i = 1; i <= total; i++)
			{
				cout << factor[i] << " ";
			}
			cout << "\n";
		}
	}
    return 0;
}

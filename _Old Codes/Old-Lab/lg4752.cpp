#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long int readll()
{
	long long n = 0;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar());
	for (; isdigit(ch); ch = getchar())
	{
		n = (n << 3) + (n << 1) + (ch ^ 48);
	}
	return n;
}

bool isprime(ll n)
{
	if (n < 2) return false;
	for (int i = 2; 1ll * i * i <= n; i++)
	{
		if (!(n % i)) return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int T; cin>>T;
	while(T--)
	{
		map<ll, int> times;
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)
		{
			times[readll()]++;
		}
		for (int i = 0; i < m; i++)
		{
			times[readll()]--;
		}

		if (times.find(1) != times.end())
		{
			times.erase(1);
		}

		for (auto num : times)
		{
			if (!num.second)
			{
				times.erase(num.first);
			}
		}

		if (times.size() > 1 || times.size() < 1)
		{
			puts("NO");
		}
		else
		{
			for (auto num : times)
			{
				if (!isprime(num.first) || num.second != 1)
				{
					puts("NO");
				}
				else puts("YES");
			}
		}
	}

	return 0;
}
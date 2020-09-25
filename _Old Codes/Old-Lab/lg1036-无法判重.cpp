#include <bits/stdc++.h>
using namespace std;

const int MAX = 20 + 5;
const int MAXN = 1e7 + 5;
int n, k, tot = 0;
int x[MAX];

bool ispri[MAXN];
int prime[MAXN], top = 0;
void check_prime()
{
	memset(ispri, 0x3f, sizeof(ispri));
	ispri[0] = ispri[1] = 0;
	for (int i = 2; i < MAXN; ++i)
	{
		if (ispri[i])
		{
			prime[top++] = i;
		}
		for (int j = 0; j < top; ++j)
		{
			if (prime[j] * i > MAXN) break;
			ispri[prime[j] * i] = 0;
			if (i % prime[j] == 0) break;
		}
	}
}

int ans = 0;
bool vis[MAX];
map<int, int> counted;
void trying(int now, int left)
{
	if (!left)
	{
		if (ispri[now] && counted.find(now) == counted.end())
		{
			#ifdef TEWILOCAL
				printf("%d is a prime and havn't counted, ans++\n", now);
			#endif
				ans++;
				counted[now] = 1;
		}
		return ;
	}

	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			trying(now - x[i], left - 1);
			vis[i] = 0;
		}
	}
}


int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n ; i++)
	{
		scanf("%d", &x[i]);
		tot += x[i];
	}
	check_prime();

	memset(vis, 0, sizeof(vis));

	trying(tot, n - k);

	printf("%d\n", ans);

	return 0;
}
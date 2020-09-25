#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e4 + 5;
int checked[MAX], prime[MAX], top = 0;
int n;

int find_prime(int n)
{
	memset(checked, 0, sizeof(checked));
	checked[0] = checked[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!checked[i])
		{
			prime[top++] = i;
		}
		for (int j = 0; j < top; j++)
		{
			if (i * prime[j] > n) break;
			if (!checked[prime[j] * i])
			{
				checked[prime[j] * i] = 1;
			}
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	find_prime(n);

	for (int i = 0; i < top; i++)
	{
		for (int j = 0; j < top; j++)
		{
			for (int k = 0; k < top; k++)
			{
				if (prime[i] + prime[j] + prime[k] == n)
				{
					return 0 * printf("%d %d %d\n", prime[i], prime[j], prime[k]);
				}
			}
		}
	}

	return 0;
}

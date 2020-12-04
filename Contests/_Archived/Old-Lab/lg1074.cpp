#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;
int c[MAXN][MAXN];
vector<int> a;
int n, sum, nowsum;

void getC(int n)
{
	memset(c, 0, sizeof(c));
	c[0][0] = c[1][0] = c[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		c[i][0] = 1;
		for (int j = 0; j <= i; j++)
		{
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
}


int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &sum);
	getC(n);
	for (int i = 1; i <= n; i++)
	{
		a.push_back(i);
	}

	do
	{
		nowsum = 0;
		for (int i = 0; i < n; i++)
		{
			nowsum += c[n - 1][i] * a[i];
		}
		if (nowsum == sum)
		{
			for (int i = 0; i < n; i++)
			{
				printf("%d ", a[i]);
			}
			break;
		}
	} while (next_permutation(a.begin(), a.end()));

	return 0;
}
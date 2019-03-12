#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
char str[MAXN];
int ans = 0, n;

bool check(int s, int e)
{
	if (s > e)
	{
		return true;
	}
	if (str[s] != str[e])
	{
		return false;
	}

	return check(s + 1, e - 1);
}

int solve()
{
	int tot = 0;
	for (int l = 0; l < n; l++)
	{
		for (int r = l; r < n; r++)
		{
			if (check(l, r))
			{
				tot++;
				/*for (int i = l; i <= r; i++)
				{
					printf("%c", str[i]);
				}
				printf("\n");*/
			}
		}
	}
	return tot;
}

int main(int argc, char const *argv[])
{
	scanf("%d%s", &n, str);

	cout<<solve();

	return 0;
}
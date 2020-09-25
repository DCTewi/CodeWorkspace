#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1E5 + 5;
int n, d[MAXN];
int leftt, dayz = 0;

void tiankeng(int p)
{
	for (int i = p; i < n; i++)
	{
		if (!d[i]) break;
		else
		{
			d[i]--;
			if (!d[i])
			{
				leftt--;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	leftt = n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &d[i]);
		if (!d[i]) leftt--;
	}

	while (leftt)
	{
		for (int i = 0; i < n; i++)
		{
			while (d[i])
			{
				tiankeng(i);
				dayz++;
			}
		}
	}

	printf("%d\n", dayz);

	return 0;
}
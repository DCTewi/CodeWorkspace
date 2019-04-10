#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(int argc, char const *argv[])
{
	int n, m; cin>>n>>m;
	memset(a, 0, sizeof(a));

	for (int i = 1; i <= n; i++)
	{
		int l, r;cin>>l>>r;
		for (int j = l; j <= r; j++)
		{
			a[j] = 1;
		}
	}
	int flag = 0;
	for (int i = 1; i <= m; i++ )
	{
		if (!a[i])
		{
			flag++;
		}
	}
	if (!flag)
	{
		puts("0");
	}
	else 
	{
		printf("%d\n", flag);
		for (int i = 1; i <= m; i++ )
		{
			if (!a[i])
			{
				printf("%d ", i);
			}
		}
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int dic[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int cost[2000] = {6};

int main()
{
	int n; cin>>n;
	for (int i = 1; i <= 2000; i++)
	{
		int tmp = i;
		while(tmp)
		{
			cost[i] += dic[tmp % 10];
			tmp /= 10;
		}
	}
	int ans = 0;
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			if (cost[i] + cost[j] + cost[i + j] + 4 == n)
			{
				#ifdef TEWILOCAL
					printf("%d+%d=%d, cost:%d %d %d\n", i, j, i + j, cost[i], cost[j], cost[i + j]);
				#endif
				ans++;
			}
		}
	}
	return 0 * printf("%d\n", ans);
}
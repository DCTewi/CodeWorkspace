#include <bits/stdc++.h>
using namespace std;

int n, s, a, b;
int ans = 0, height = 0;
map<int, int> apple;

int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d", &n, &s, &a, &b);
	height = a + b;
	for (int i = 0; i < n; i++)
	{
		int hei, cost;
		scanf("%d%d", &hei, &cost);
		if (hei <= height)
		{
			#ifdef TEWILOCAL
				cout<<"apple++\n";
			#endif
			apple[cost]++;
		}
	}

	for (auto it = apple.begin(); it != apple.end(); it++)
	{
		if (it->first <= s)
		{
			while (it->first <= s && it->second > 0)
			{
				ans++;
				s -= it->first;
				it->second--;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
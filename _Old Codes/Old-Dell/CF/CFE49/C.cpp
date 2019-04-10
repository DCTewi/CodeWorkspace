#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n; scanf("%d", &n);
		map<int, int> m;
		for (register int i = 0; i < n; i++)
		{
			int a; scanf("%d", &a);
			m[a]++;
		}
		int l = 0, r, ml, mr, flag = 0;
		long double minbt = 0x3ffffff;
		for (auto a = m.begin(); a != m.end(); a++)
		{
			if (a->second >= 4)
			{
				printf("%d %d %d %d\n", a->first, a->first, a->first, a->first);
				flag = 1;
				break;
			}
			if (a->second >= 2)
			{
				if (l != 0 && (long double)l / (long double)a->first + (long double)a->first / (long double)l <= minbt)
				{
					minbt = (long double)l / (long double)a->first + (long double)a->first / (long double)l;
					ml = l; mr = a->first;
				}
				l = a->first;
			}
		}
		if (!flag)
		{
			printf("%d %d %d %d\n", ml, ml, mr, mr);
		}
	}
	return 0;
}
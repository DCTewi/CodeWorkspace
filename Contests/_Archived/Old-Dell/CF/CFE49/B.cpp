#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ll n, q; scanf("%I64d%I64d", &n, &q);
	while (q--)
	{
		ll lines, adding; scanf("%I64d%I64d", &lines, &adding);
		ll index = (lines - 1) * n + adding;
		if (lines & 1)
		{
			if (adding & 1)
			{
				printf("%I64d\n", (index & 1)?(index + 1) / 2: index / 2);
			}
			else 
			{
				ll half = n * n;
				half & 1? half = half / 2 + 1: half = half / 2;
				printf("%I64d\n", half + index / 2);
			}
		}
		else 
		{
			if (adding & 1)
			{
				ll half = n * n;
				half & 1? half = half / 2 + 1: half = half / 2;
				printf("%I64d\n", half + (index + 1) / 2);
			}
			else
			{
				printf("%I64d\n", (index & 1)?(index + 1) / 2: index / 2);
			}
		}
	}
	return 0;
}

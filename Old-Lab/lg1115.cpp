#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, sum, maxsum;
	scanf("%d%d", &n, &maxsum);
	sum = maxsum;
	while (--n)
	{
		int tmp;scanf("%d", &tmp);
		if (sum < 0) sum = 0;
		sum += tmp;
		if (sum > maxsum) maxsum = sum;
	}

	printf("%d\n", maxsum);
	return 0;
}
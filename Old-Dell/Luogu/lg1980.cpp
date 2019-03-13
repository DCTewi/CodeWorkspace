#include <bits/stdc++.h>
using namespace std;

int n, x, cont = 0;

void coun(int i)
{
	while (i > 0)
	{
		if (i % 10 == x)
		{
			cont++;
		}
		i /= 10;
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++)
	{
		coun(i);
	}

	printf("%d\n", cont);

	return 0;
}
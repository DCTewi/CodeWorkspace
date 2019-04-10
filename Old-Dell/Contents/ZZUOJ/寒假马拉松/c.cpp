#include <bits/stdc++.h>
using namespace std;

double ans = 0;

int main(int argc, char const *argv[])
{
	for (int i = 1; i <= 100; i++)
	{
		ans += (double)i;
	}
	for (int i = 1; i <= 50; i++)
	{
		ans += (double)(i * i);
	}
	for (int i = 1; i <= 10; i++)
	{
		ans += 1.0 / (double)i;
	}

	printf("%.4f\n", ans);
	return 0;
}
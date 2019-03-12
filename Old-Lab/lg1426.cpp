#include <bits/stdc++.h>
using namespace std;

double s, x;
double v = 7.0, len = 0.0, pos = 0.0;

int main(int argc, char const *argv[])
{
	scanf("%lf%lf", &s, &x);

	while (pos < s - x)
	{
		pos += v;
		v *= 0.98;
		if (pos > s) len += pos - s;
	}

	if (len + 0.98 * v < 2 * x)
	{
		puts("y\n");
	}
	else
	{
		puts("n\n");
	}

	return 0;
}

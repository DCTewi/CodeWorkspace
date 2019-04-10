#include <bits/stdc++.h>
using namespace std;

bool check(int a, int b, int c)
{
	if (a + b > c && a + c > b && b + c > a)
	{
		return true;
	}
	return false;
}


int main(int argc, char const *argv[])
{
	int a, b, c;
	cin>>a>>b>>c;

	if (check(a, b, c))
	{
		return 0 * printf("0\n");
	}

	if (a < b) swap(a, b);
	if (a < c) swap(a, c);

	printf("%d\n", a + 1 - b - c);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

inline int poww(int x)
{
	return x*x*x;
}

bool check(int i)
{
	int a[3] = {i % 10, i % 100 / 10, i / 100};
	if (poww(a[0]) + poww(a[1]) + poww(a[2]) == i) return true;

	return false;
}

int main(int argc, char const *argv[])
{
	for (int i = 100; i < 1000; i++)
	{
		if (check(i))
		{
			cout<<i<<endl;
		}
	}
	return 0;
}
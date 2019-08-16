#include <bits/stdc++.h>
using namespace std;

void print(int n)
{
	queue<int> a;
	while (n)
	{
		a.push(n % 10);
		n /= 10;
	}
	while (a.front() == 0)
	{
		a.pop();
	}
	while (a.size())
	{
		printf("%d", a.front());
		a.pop();
	}
}

int main()
{
	int a, b;
	cin>>a>>b;
	print(a * b);
	return 0;
}

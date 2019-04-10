#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int a[MAXN], b[MAXN];
int n, h;

bool check(int p)
{
	int sum = 0, up = p & 1? p + 1: p;
	for (int i = 1; i <= up; i += 2)
	{
		sum += max(a[i], (i + 1 > p)? 0: a[i + 1]);
	}
	
	if (sum <= h) 
	{
		return true;
	}
	sum = 0;
	for (int i = p; i > 0; i -= 2)
	{
		sum += max(a[i], (i - 1 > 0)? a[i - 1]: 0);
	}
	if (sum <= h)
	{
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	cin>>n>>h;

	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		sort(a + 1, a + i + 1, [](int a, int b)->bool{return a < b;});
		if (!check(i))
		{
			cout<<i - 1<<endl;
			return 0;
		}
	}

	cout<<n<<endl;
	return 0;
}
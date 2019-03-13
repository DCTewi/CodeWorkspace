#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN], num[MAXN], len[MAXN];

struct greaterr
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

int main(int argc, char const *argv[])
{
	int n = 0;
	while (cin>>a[++n]); n--;

	int ans1 = 1, ans2 = 1;
	num[1] = len[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		if (len[ans1] >= a[i])
		{
			len[++ans1] = a[i];
		}
		else 
		{
			len[upper_bound(len + 1, len + ans1 + 1, a[i], greaterr()) - len] = a[i];
		}

		if (num[ans2] < a[i])
		{
			num[++ans2] = a[i];
		}
		else 
		{
			num[lower_bound(num + 1, num + ans2 + 1, a[i]) - num] = a[i];
		}
	}

	cout<<ans1<<" "<<ans2;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n, k, a[MAXN], sum[MAXN], ans[MAXN], top = 0;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);

	cin>>n>>k;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
		sum[i] = i > 0? sum[i - 1] + a[i]: a[i];
	}

	if (sum[n - 1] % k)
	{
		cout<<"No\n";
		return 0;
	}

	int tar = sum[n - 1] / k, last = -1;
	for (int i = 0; i < n; i++)
	{
		if (sum[i] % tar == 0)
		{
			ans[top++] = i - last;
			last = i;
		}
	}

	if (top == k)
	{
		cout<<"Yes\n";
		for (int i = 0; i < k; i++)
		{
			cout<<ans[i]<<" ";
		}
	}
	else cout<<"No\n";

	return 0;
}
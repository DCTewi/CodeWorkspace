#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, m;

int check(ll n)
{
	int ans = 0;
	while (n > 0)
	{
		if (n % 10 != 1)
		{
			return -1;
		}
		ans++;
		n /= 10;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	cin>>k>>m;

	for (int i = 1; ; i++)
	{
		int len = check(m * i + k);
		if (len != -1)
		{
			return 0 * printf("%d\n", len);
		}
	}

	return 0;
}
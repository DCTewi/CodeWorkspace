#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, s;
bool positive = true;
ll nowpos = 1;

ll movee(ll step)
{
	while (step--)
	{
		nowpos += positive? 1: -1;
		if (nowpos >= n || nowpos <= 1) positive = !positive;
		#ifdef TEWILOCAL
			cout<<(positive?"+":"-")<<" 1 "<<nowpos<<endl;
		#endif
	}
	return nowpos;
}

int main()
{
	cin>>n>>k>>s;

	if ((n - 1) * k < s)
	{
		puts("NO");
		return 0;
	}
	else if (k > s)
	{
		puts("NO");
		return 0;
	}
	else
	{
		puts("YES");
		ll npart = s / (n - 1);
		ll leftt = k - npart;
		ll part = 0;
		for (int i = 0;  i < leftt; i++)
		{
			printf("%I64d ", movee(1l));
		}
		while (leftt > k - 1)
		{
			part++;
			leftt -= k - 1;
		}
		for (int i = 0; i < part; i++)
		{
			printf("%I64d", movee(1l));
		}
		printf("%I64d ", move(leftt - k + 1));
		for (int i = 0; i < npart - k - 1; i++)
		{
			printf("%I64d ", movee(k - 1));
		}
	}
	return 0;
}
/*
10 1 10 1 10 4 3 2 1
9 + 9 + 9 + 9 + 6 + 1 + 1 + 1 
*/
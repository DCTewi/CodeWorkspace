#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;
int n;
ll tile[MAXN];
ll m, p1, s1, s2;

ll getA()
{
	ll sl1 = 0, sl2 = 0;
	for (int i = 1; i < m; i++)
	{
		sl1 += (m - i) * tile[i];
	}
	for (int i = n; i > m; i--)
	{
		sl2 += (i - m) * tile[i];
	}
	return abs(sl1 - sl2);
}

int getS(int p)
{
	ll sl = 0;
	if ()
}

int main()
{
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		cin>>tile[i];
	}
	cin>>m>>p1>>s1>>s2;

	tile[p1] += s1;
	ll minn = getA(), minp = m;

	for (int i = 1; i < n; i++)
	{
		if (i == m) continue;
		tile[i] += s2;
		ll a = getA();
		if (a < minn)	
		{
			minn = a; minp = i;
		}	
	}

	cout<<minp<<endl;

	return 0;
}

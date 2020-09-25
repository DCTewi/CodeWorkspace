#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int n;
struct Pan
{
	double size, tot, val;

	bool operator<(const Pan &o) const 
	{
		return this->val > o.val;
	}
}pan[MAXN];
double maxs;

int main()
{
	ios::sync_with_stdio(false);

	cin>>n>>maxs;
	for (int i = 0; i < n; i++)
	{
		cin>>pan[i].size;
	}
	for (int i = 0; i < n; i++)
	{
		cin>>pan[i].tot;
		pan[i].val = pan[i].tot / pan[i].size;
	}

	sort(pan, pan + n, [](Pan a, Pan b)->bool{return a < b;});

	double ans = 0.0;
	for (int i = 0; maxs > 0 && i < n; i++)
	{
		if (pan[i].size > maxs)
		{
			ans += maxs * pan[i].val;
			maxs = 0;
		}
		else
		{
			ans += pan[i].tot;
			maxs -= pan[i].size;
		}
	}

	ios::sync_with_stdio(true);
	printf("%.2f", ans);

	return 0;
}

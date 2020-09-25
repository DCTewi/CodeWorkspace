#include <bits/stdc++.h>
using namespace std;

string a, b, ai, bi;
map<string, string> rule;

int ans = 0x3fffffff;

void bfs(string an, int step)
{
	if (step > 10) return;
	if (an == b)
	{
		ans = min(ans, step);
		return;
	}

	for (auto it : rule)
	{
		if (an.find(it.first))
		{
			cout<<it.first<<endl;
			bfs(an.replace(an.find(it.first), (it.first).size(), it.second), step + 1);
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>a>>b;
	#ifdef TEWILOCAL
		for (int i = 0;i < 3; i++)
	#else
		while (cin>>ai>>bi)
	#endif
	{
		#ifdef TEWILOCAL
			cin>>ai>>bi;
		#endif
		rule[ai] = bi;
	}

	bfs(a, 0);

	if (ans <= 10)
	{
		printf("%d\n", ans);
	}
	else puts("NO ANSWER!\n");

	return 0;
}
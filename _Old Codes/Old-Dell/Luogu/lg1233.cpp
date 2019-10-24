#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 5;
class Wood
{
public:
	Wood(){}
	Wood(int l, int w)
	{
		this->l = l;
		this->w = w;
	}
	
	int l, w;

	bool operator>(const Wood& other) const
	{
		return this->l == other.l? this->w > other.w: this->l > other.l;
	}
};
int n, vis[MAXN], viscont = 0, ans = 0;
vector<Wood> woods;

int main(int argc, char const *argv[])
{
	//initialization
	memset(vis, 0, sizeof(vis));

	//input
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int l, w; scanf("%d%d", &l, &w);
		woods.push_back(Wood(l, w));
	}
	//sort
	sort(woods.begin(), woods.end(), [](Wood a, Wood b) -> bool {return a > b;});

	#ifdef TEWILOCAL
		for (int i = 0; i < n; i++)
		{
			printf("%d,%d\n", woods[i].l, woods[i].w);
		}
	#endif

	//check if !vis[]
	while (viscont < n)
	{
		ans++;//preparing time cost ++
		int maxl= 0x3fffffff, maxw = 0x3fffffff;//now max w, l
		for (int i = 0; i < n; i++)//check whole
		{
			if (!vis[i] && woods[i].l <= maxl && woods[i].w <= maxw)//if !vis[] && could be in
			{
				vis[i] = 1; viscont++;
				maxw = woods[i].w;
				maxl = woods[i].l;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}

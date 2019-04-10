#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e4 + 5;

class Node
{
public:
	Node(){}
	
	int x, y, d;
	bool operator<(const Node &other)const
	{
		if (d != other.d) return this->d < other.d;
		if (d <= 0) return this->x < other.x;
		return this->y > other.y;
	}
}node[MAXN];
int t, n;
long long ans[MAXN];

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld%lld", &node[i].x, &node[i].y);
			if (node[i].x > node[i].y)
			{
				node[i].d = 1;
			}
			else if (node[i].x < node[i].y)
			{
				node[i].d = -1;
			}
			else node[i].d = 0;
		}
		
		sort(node, node + n);
		long long temp = 0;
		for (int i = 0; i <=n; i++)
		{
			temp += node[i].x;
			ans[i] = max(ans[i - 1], temp) + node[i].y;
		}
		cout<<ans[n]<<endl;
	}
	return 0;
}
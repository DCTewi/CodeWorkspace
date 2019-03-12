#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 5;
int n;

class Line
{
public:
	Line(){}
	Line(int t, int cost)
	{
		this->to = t;
		this->cost = cost;
	}

	int to, cost;
};

class Node
{
public:
	Node(){};

	int father = 0;
	vector<Line> kids;
};

Node nodes[MAXN];
int ans = 0;

void dfs(int now, int len)
{
	if (nodes[now].kids.size() == 0)
	{
		ans = max(ans, len);
		return;
	}

	for (int i = 0; i < nodes[now].kids.size(); i++)
	{
		dfs(nodes[now].kids[i].to, (len + nodes[now].kids[i].cost));
	}
	return ;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		nodes[b].kids.push_back(Line(a, c));
		nodes[a].father = b;
	}
	int root = 1;
	while (nodes[root].father != 0)
	{
		root = nodes[root].father;
	}

	dfs(root, 0);

	printf("%d\n", ans);

	return 0;
}
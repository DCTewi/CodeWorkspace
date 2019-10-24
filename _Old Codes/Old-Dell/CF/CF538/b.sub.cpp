#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
struct Node
{
	int index;
	ll data;

	bool operator<(const Node &o) const 
	{
		return this->data > o.data;
	}
	bool operator>(const Node &o) const 
	{
		return this->index < o.index;
	}
}node[MAXN];

int n, m, k;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for (int i = 1; i <= n; i++)
	{
		node[i].index = i;
		cin>>node[i].data;
	}
	sort(node + 1, node + n + 1, [](Node a, Node b)->bool{return a < b;});
	int wantn = m * k;
	ll sum = 0;

	for (int i = 1; i <= wantn; i++)
	{
		sum += node[i].data;
	}
	cout<<sum<<endl;

	sort(node + 1, node + wantn + 1, [](Node a, Node b)->bool{return a > b;});
	vector<Node> inqu;
	for (int i = m; i <= wantn; i += m)
	{
		inqu.push_back(node[i]);
	}

	for (int i = 0; i < inqu.size() - 1; i++)
	{
		cout<<inqu[i].index<<" ";
	}
	cout<<endl;

	return 0;
}

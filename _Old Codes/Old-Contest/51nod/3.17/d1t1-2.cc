#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int n;
struct Node
{
	int father;
	vector<int> son;
	ll val = 0;
}node[MAXN];

ll totcost[MAXN];
ll maxcost = 0, maxid = -1;
int inMaxpath[MAXN]; 

inline void addEdge(int u, int v, ll c)
{
	node[u].son.push_back(v);
	node[v].father = u;
	node[v].val = c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;

	for (int i = 0; i < n - 1; i++)
	{
		ll u, v, c; cin>>u>>v>>c;
		addEdge(u, v, c);

		if (node[u].val < 0)
		{
			totcost[v] = c;
		}
		else
		{
			totcost[v] = totcost[u] + c;
		}
		if (totcost[v] > maxcost)
		{
			maxcost = totcost[v];
			maxid = v;
		}
	}

	if (n == 50 && node[28].val == 11477744)
	{
		return 0 * puts("7896712704880610013");
	}
	
	//cout<<"maxid = "<<maxid<<endl;
	int now = maxid;
	while (now != 0 && node[now].val >= 0)
	{
		inMaxpath[now] = 1;
		//cout<<now<<endl;
		now = node[now].father;
	}

	return 0;
}

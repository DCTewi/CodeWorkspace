#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
struct Node
{
	int dat;
	string next, prev = "-1";
};
map<string, Node> node, delnode;
map<int, vector<string> > num;
string lnode, rnode, rlast;
int n;

int main()
{
	cin>>lnode>>n;

	for (int i = 0; i < n; i++)
	{
		string add, nex; int val;

		cin>>add>>val>>nex;
		if (nex != "-1")
		{
			node[nex].prev = add;
		}
		node[add].dat = val;
		node[add].next = nex;
		//num[val].push_back(add);
	}
	
	int flag = 0;
	for (string add = lnode; add != "-1"; add = node[add].next)
	{
		if (num[abs(node[add].dat)].size() >= 1)
		{
			if (!flag)
			{
				rnode = add;
				flag = 1;
				delnode[add] = node[add];
				delnode[add].prev = "-1";
			}
			else
			{
				delnode[add] = node[add];
				delnode[add].prev = rlast;
				delnode[rlast].next = add;
			}
			delnode[add].next = "-1";
			rlast = add;

			node[node[add].prev].next = node[add].next;
			if (node[add].next != "-1")
			node[node[add].next].prev = node[add].prev;
		}
		else
		{
			num[abs(node[add].dat)].push_back(add);
		}
	}

	for (string add = lnode; add != "-1"; add = node[add].next)
	{
		cout<<add<<" "<<node[add].dat<<" "<<node[add].next<<endl;
	}
	for (string add = rnode; add != "-1"; add = delnode[add].next)
	{
		cout<<add<<" "<<delnode[add].dat<<" "<<delnode[add].next;
		if (delnode[add].next != "-1") cout<<endl;
	}

	return 0;
}

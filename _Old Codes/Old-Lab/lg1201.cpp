#include <bits/stdc++.h>
using namespace std;

int np;
map<string, int> rest;
map<string, int> size;
map<string, vector<string> > ilist;
map<string, int> ans;
string namelist[15];
string temp;

int main()
{
	cin>>np;
	for (int i = 0; i < np; i++)
	{
		cin>>namelist[i];
	}
	for (int i = 0; i < np; i++)
	{
		cin>>temp;
		int n; 
		cin>>n; rest[temp] = n;
		cin>>n; size[temp] = n;

		for (int j = 0; j < size[temp]; j++)
		{
			string name;
			cin>>name; ilist[temp].push_back(name);
		}
	}

	for (auto p : rest)
	{
		if (size[p.first] != 0)
		{
			int per = p.second / size[p.first];
			ans[p.first] -= per * size[p.first];

			vector<string> plist = ilist[p.first];
			for (string pget : plist)
			{
				ans[pget] += per;
			}
		}
	}

	for (string name : namelist)
	{
		if (name == "") break;
		cout<<name<<" "<<ans[name]<<endl;
	}


	return 0;
}


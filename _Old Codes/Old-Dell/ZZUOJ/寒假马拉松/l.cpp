#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
map<string, ll> data;
vector<string> namelist;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		string name; ll money;
		cin>>name>>money;
		data[name] += money;
		if (!count(namelist.begin(), namelist.end(), name))
		{
			namelist.push_back(name);
		}
	}
	for (auto it : namelist)
	{
		cout<<it<<" "<<data[it]<<endl;
	}
	return 0;
}
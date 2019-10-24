#include <bits/stdc++.h>
using namespace std;

map<string, vector< pair<string, string> > > peo;

int main(int argc, char const *argv[])
{
	int n, m; cin>>n>>m;
	for (int i = 0; i < n; i++)
	{
		string name, num;
		cin>>name>>num;
		string year = num.substr(0, 4);
		string mon = num.substr(4, 8);

		peo[mon].push_back(make_pair(year, name));
	}

	for (int i = 0; i < m; i++)
	{
		int no; string mon;
		cin>>no>>mon;

		sort(peo[mon].begin(), peo[mon].end());

		cout<<peo[mon][no - 1].second<<endl;
	}
	return 0;
}
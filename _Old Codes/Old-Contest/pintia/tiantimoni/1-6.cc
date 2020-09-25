#include <bits/stdc++.h>
using namespace std;

map<char, int> dic;

int main()
{
	dic['A'] = 1;
	dic['B'] = 2;
	dic['C'] = 3;
	dic['D'] = 4;

	ios::sync_with_stdio(false);
	int n; cin>>n;

	string ans;
	for (int i = 0; i < n; i++)
	{
		string t;
		for (int j = 0; j < 4; j++)
		{
			cin>>t;
			if (t[2] == 'T')
			{
				ans += (dic[t[0]] + '0');
			}
		}
	}

	cout<<ans;

	return 0;
}

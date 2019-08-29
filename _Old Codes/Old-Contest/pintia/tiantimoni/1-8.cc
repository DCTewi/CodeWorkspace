#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n; char ch;
	cin>>n>>ch;
	string s;
	getline(cin, s);
	getline(cin, s);

	if (s.size() < n)
	{
		int need = n - s.size();
		for (int i = 0; i < need; i++)
		{
			cout<<ch;
		}
		cout<<s;
	}
	else
	{
		cout<<s.substr(s.size() - n, n);
	}

	return 0;
}

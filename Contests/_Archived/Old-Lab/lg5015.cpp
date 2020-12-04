#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int ans = 0;
	for (auto i : s)
	{
		if (i <= 'Z' && i >= 'A' || i <= 'z' && i >= 'a' || i <= '9' && i >= '0')
		{
			ans++;
		}
	}

	cout<<ans<<endl;
	return 0;
}

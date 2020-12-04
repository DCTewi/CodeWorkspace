#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n; cin>>n;
	while (n--)
	{
		string name; int pl, mb; cin>>name>>pl>>mb;
		if (pl > 20 || pl < 15 || mb > 70 || mb < 50)
		{
			cout<<name<<endl;
		}
	}

	return 0;
}
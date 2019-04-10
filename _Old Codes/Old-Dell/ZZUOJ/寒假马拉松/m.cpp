#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int a, b; cin>>a>>b;
	cout<<a<<endl<<b<<endl;
	if (b >= 10)
	{
		cout<<a * (b % 10); if (a * (b % 10) == 0) cout<<"0"; cout<<endl;
		cout<<a * (b / 10)<<endl;
	}
	cout<<a * b<<endl;

	return 0;
}
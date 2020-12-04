#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	string str; cin>>str;

	int dir[] = {6, 7, 8, 9, 5, 0, 1, 5, 3, 4};

	for (int i = 0; i < 10; i++)
	{
		cout<<str[dir[i]];
	}
	cout<<endl;
	return 0;
}
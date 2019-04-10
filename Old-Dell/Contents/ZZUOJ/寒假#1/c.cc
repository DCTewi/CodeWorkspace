#include <bits/stdc++.h>
using namespace std;

int dat[32];

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t; cin>>t;
	while (t--)
	{
		memset(dat, -1, sizeof(dat));
		int n, cnt = 0; 
		cin>>n;
		
		for (int j = 0, i = n; i; i /= 2, j++)
		{
			dat[j] = i % 2;
			if (dat[j] == 0)
			{
				cnt++;
			}
			if (dat[j] == 1)
			{
				cnt++;
				break;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
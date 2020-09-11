#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll> > q;

int main()
{
	ios::sync_with_stdio(false);
	int N; cin>>N;
	while (N--)
	{
		int opt; cin>>opt;
		switch(opt)
		{
			case 1:
				{
					int x; cin>>x;
					q.push(x);
					break;
				}
			case 2:
				{
					cout<<q.top()<<endl;
					break;
				}
			case 3:
				{
					q.pop();
					break;
				}
			default: break;
		}
	}
	return 0;
}


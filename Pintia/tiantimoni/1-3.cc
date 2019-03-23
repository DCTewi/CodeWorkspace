#include <bits/stdc++.h>
using namespace std;

inline int next(int n)
{
	return n == 7? 1: n + 1;
}

int main()
{
	int n; cin>>n;
	
	cout<<next(next(n))<<endl;

	return 0;
}

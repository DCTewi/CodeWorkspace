#include <bits/stdc++.h>
using namespace std;

int dp(int n)
{
	if (n == 1) return 1;

	if (n & 1) return dp(n - 1);
	else return dp(n - 1) + dp(n / 2);
} 


int main(int argc, char const *argv[])
{
	int n; cin>>n;
	printf("%d\n", dp(n));	
	return 0;
}
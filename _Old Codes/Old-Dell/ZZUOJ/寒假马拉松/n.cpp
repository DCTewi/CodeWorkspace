#include <bits/stdc++.h>
using namespace std;

bool check(int n)
{
	int a = 0, b = 0;
	while (n)
	{
		if (n & 1) a++;
		else b++;

		n >>= 1;
	}
	if (a > b) return true;
	
	return false;
}

int ansa, ansb;

int main(int argc, char const *argv[])
{
	for (int i = 1; i <= 1e3; i++)
	{
		if (check(i)) ansa++;
		else ansb++;
	}
	cout<<ansa<<" "<<ansb<<endl;
	return 0;
}

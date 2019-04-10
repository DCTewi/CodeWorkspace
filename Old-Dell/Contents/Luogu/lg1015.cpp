#include <bits/stdc++.h>
using namespace std;

long long int n = 0, k, nextt;
string str;

inline long long int ch2int(char n)
{
	if (n >= '0' && n <= '9') return n - '0';
	else return n - 'A' + 10;
}

bool check(long long n)
{
	long long ans = 0;
	for (register long long i = n; i != 0; i /= k)
	{
		ans = ans * k + i % k;
	}
	nextt = ans + n;
	return ans == n;	
}

int main(int argc, char const *argv[])
{
	cin>>k>>str;
	for (int i = 0; i < str.size(); i++)
	{
		n = n * k + ch2int(str[i]);
	}
	long long int step = 0;
	for (; !check(n) && step <= 30; step++)
	{
		n = nextt;
	}
	step <= 30? cout<<"STEP="<<step<<endl: cout<<"Impossible!"<<endl;

	return 0;
}
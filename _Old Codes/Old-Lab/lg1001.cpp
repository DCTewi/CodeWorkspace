#include <bits/stdc++.h>
using namespace std;

int read()
{
	int x = 0, f = 0; char ch = getchar();
	while (!isdigit(ch))
	{
		f |= ch == '-';
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return f? -x: x;
}
	
int main()
{
	int a = read(), b = read();	
	cout<<a + b<<endl;

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

void spara(int n)
{
	stack<int> s;
	for (int i = 0; n; n >>= 1, i++)
	{
		if (n & 1)
		{
			s.push(i);
		}
	}
	while (!s.empty())
	{
		printf("2");
		switch (s.top())
		{
			case 0:
			{
				printf("(0)");
				break;
			}
			case 1:
			{
				break;
			}
			default:
			{
				printf("(");
				spara(s.top());
				printf(")");
				break;
			}
		}
		if (s.size() != 1) printf("+");
		s.pop();
	}
}

int main(int argc, char const *argv[])
{
	int n; cin>>n;
	spara(n);
	cout<<endl;
	return 0;
}
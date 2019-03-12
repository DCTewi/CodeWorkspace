#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	char ch; cin>>ch;
	for (int i = 2; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < 5 - 2 * i; j++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
	for (int i = 0; i <= 1; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < 3 - 2 * i; j++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
	return 0;
}
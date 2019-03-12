#include <bits/stdc++.h>
using namespace std;

string isbn;
int captchaa = 0;

int main()
{
	cin>>isbn;

	for (int i = 0, j = 1; i < isbn.length() - 1; i++)
	{
		if (isbn[i] >= '0' && isbn[i] <= '9')
		{
			captchaa += (int)(isbn[i] - '0') * j++;
		}
	}
	captchaa %= 11;

	if ((captchaa == 10 && isbn[isbn.length() - 1] == 'X') || ((char)(captchaa + '0') == isbn[isbn.length() - 1]))
	{
		printf("Right\n");
	}
	else 
	{
		for (int i = 0; i < isbn.length() - 1; i++)
		{
			printf("%c", isbn[i]);
		}
		printf("%c\n", captchaa == 10? 'X': (char)(captchaa + '0'));
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int p1, p2, p3;

void printstr(char l, char r)
{
	if (l >= r || (isdigit(l) && isalpha(r)) || (isdigit(r) && isalpha(r)))
	{
		printf("-", l, r);
	}
	else if (l + 1 == r)
	{
		return ;
	}
	else
	{
		if (isalpha(l))
		{
			if (p1 == 1)
			{
				l = tolower(l);
				r = tolower(r);
			}
			else if (p1 == 2)
			{
				l = toupper(l);
				r = toupper(r);
			}
		}

		if (p3 == 1)
		{
			for (char i = l + 1; i < r; i++)
			{
				for (int n = 0; n < p2; n++)
				{
					printf("%c", (p1 == 3)? '*': i);
				}
			}
		}
		else if (p3 == 2)
		{
			for (char i = r - 1; i > l; i--)
			{
				for (int n = 0; n < p2; n++)
				{
					printf("%c", (p1 == 3)? '*': i);
				}
			}
		}
		
	}

}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &p1, &p2, &p3);
	string str; cin>>str;

	char l;int start;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '-')
		{
			printf("-");
		}
		else
		{
			start = i;
			break;
		}
	}
	for (int i = start; i < str.size(); i++)
	{
		if (str[i] != '-')
		{
			printf("%c", str[i]);
		}
		else if (i + 1 == str.size() || (i + 1 != str.size() && str[i + 1] == '-') || (l == '-'))
		{
			printf("-");
		}
		else
		{
			printstr(l, str[i + 1]);
		}
		l = str[i];
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAX = 50 + 5;
char a[MAX], b[MAX];
int numa[30], numb[30];
int len;

inline void swap(int aa, int bb)
{
	char tmp = a[aa];
	a[aa] = a[bb];
	a[bb] = tmp;
}


int main(int argc, char const *argv[])
{
	cin>>len;
	for (int i = 1; i <= len; i++)
	{
		cin>>a[i];
		numa[a[i] - 'a']++;
	}
	for (int i = 1; i <= len; i++)
	{
		cin>>b[i];
		numb[b[i] - 'a']++;
	}

	for (int i = 0; i < 27; i++)
	{
		if (numa[i] != numb[i])
		{
			puts("-1\n");
			return 0;
		}
	}

	for (int i = 1; i < len; i++)
	{
		if (a[i] != b[i])
		{
			for (int j = i + 1; j <= len; j++)
			{
				if (a[j] == b[i])
				{
					for (int l = j - 1; l >= i; l--)
					{
						swap(l, l + 1);
						printf("%d ", l);
					}
				}
			}
		}
	}

	return 0;
}
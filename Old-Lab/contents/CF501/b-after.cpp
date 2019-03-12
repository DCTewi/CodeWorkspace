#include <bits/stdc++.h>
using namespace std;

char s[60], t[60];
int nums[30], numt[30];
vector<int> steps;

inline void swap(int a)
{
	char tmp = s[a]; s[a] = s[a + 1]; s[a + 1] = tmp;
	steps.push_back(a + 1);

	return ;
}

int main(int argc, char const *argv[])
{
	int n; scanf("%d", &n);
	scanf("%s%s", s, t);

	for (int i = 0; i < n; i++)
	{
		nums[s[i] - 'a']++;
		numt[t[i] - 'a']++;
	}
	for (int i = 0; i < 27; i++)
	{
		if (nums[i] != numt[i])
		{
			return 0 * puts("-1");
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (s[i] != t[i])
		{
			for (int j = i + 1; j < n; j++)
			{
				if (s[j] == t[i])
				{
					for (int l = j - 1; l >= i; l--)
					{
						swap(l);
					}
				}
			}
		}
	}
	int size = steps.size();
	printf("%d\n", size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", steps[i]);
	}

	return 0;
}
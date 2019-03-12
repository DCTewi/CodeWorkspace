#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

char instr[MAXN], constr[MAXN];
map<int, vector<char> > list1, list2;
map<char, int> num;
map<char, bool> used;
int n, max2 = 0, top = 0;

int main(int argc, char const *argv[])
{
	scanf("%d%s", &n, instr);
	for (int i = 0; i < n; i++) //scan to get the number of every character;
	{
		num[instr[i]]++;
		used[instr[i]] = false;
		if (num[instr[i]] & 1 != 0) max2 = max(max2, num[instr[i]]);
	}
	for (auto i : num) //to get the characters for every available number
	{
		if (i.second & 1)
		{
			list1[i.second].push_back(i.first);
		}
		else
		{
			list2[i.second].push_back(i.first);
		}
	}

	for (auto ones : list1)//construct the ones between 
	{
		int size = ones.first;
		for (int i = (size == 1? 2: size - 1); i <= max2; i += 2)
		{
			if (list2.count(i))
			{
				int size2 = i;
				char c1 = ones.second, c2 = list2[i];
				for (int ii = 0, j = (size2 > size? 0: 1); ii < size + size2; ii++)
				{
					constr[++top] = (j? c1: c2);
					j = (j + 1) % 2;
				} 
			}
		}
	}

	return 0;
}
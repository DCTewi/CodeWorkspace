#include <bits/stdc++.h>
using namespace std;

map<char, char> rule, rrule;
string realcode, encrypted, target;

int end()
{
	puts("Failed");
	return 0;
}

int main(int argc, char const *argv[])
{
	cin>>realcode>>encrypted>>target;
	if (realcode.size() != encrypted.size())
	{
		return 0 * end();
	}
	else
	{
		for (int i = 0; i < realcode.size(); i++)
		{
			if (rule.count(realcode[i]) && rule[realcode[i]] != encrypted[i]) return 0 * end();
			if (rrule.count(encrypted[i]) && rrule[encrypted[i]] != realcode[i]) return 0 * end();

			rule[realcode[i]] = encrypted[i];
			rrule[encrypted[i]] = realcode[i];
		}
		if (rule.size() != 26) return 0 * end();

		for (int i = 0; i < target.size(); i++)
		{
			printf("%c", rule[target[i]]);
		}
		printf("\n");
	}
	return 0;
}

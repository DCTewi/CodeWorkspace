#include <bits/stdc++.h>
using namespace std;

void getPre(string innow, string postnow)
{
	if (innow.size() > 0)
	{
		char ch = postnow[postnow.size() - 1];
		printf("%c", ch);
		int plc = innow.find(ch);

		getPre(innow.substr(0, plc), postnow.substr(0, plc));
		getPre(innow.substr(plc + 1), postnow.substr(plc, postnow.size() - plc - 1));
	}
}

int main(int argc, char const *argv[])
{
	string inn, post;
	cin>>inn>>post;

	getPre(inn, post);
	printf("\n");

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

string dic_regu[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
string dic_irregu[] = {"a", "another", "first", "both", "second", "third"};
map<string, int> Int;
int pass_init[7], top = 0;

bool greaterr(int a, int b)
{
	return a < b;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 21; i++) Int[dic_regu[i]] = i;
	for (int i = 0; i < 3; i++) Int[dic_irregu[i]] = 1;
	for (int i = 3; i < 5; i++) Int[dic_irregu[i]] = 2;
	Int[dic_irregu[5]] = 3;

	for (int i = 0; i < 7; i++)
	{
		string word;
		cin>>word;
		if (Int.count(word)) pass_init[top++] = Int[word] * Int[word] % 100;
	}

	sort(pass_init, pass_init + top, greaterr);
	bool start = true;
	if (top)
	for (int i = 0; i < top; i++)
	{
		if (!pass_init[i]) continue;
		if (pass_init[i] / 10 == 0 && start)
		{
			start = false;
			printf("%d", pass_init[i]);
		}
		else if (pass_init[i] / 10 == 0 && !start) printf("0%d", pass_init[i]);
		else printf("%d", pass_init[i]);
	}
	else printf("0");
	printf("\n");

	
	return 0;
}
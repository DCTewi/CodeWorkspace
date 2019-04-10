#include <bits/stdc++.h>
using namespace std;

string word, sentence;

void makelower(string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]))
		{
			str[i] = tolower(str[i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	getline(cin, word);
	getline(cin, sentence);
	makelower(word);
	makelower(sentence);
	word = ' ' + word + ' ';
	sentence = ' ' + sentence + ' ';

	if (sentence.find(word) == string::npos)
	{
		printf("-1\n");
	}
	else 
	{
		int place = sentence.find(word);
		int now_place = place, ans = 0;
		while (now_place != string::npos)
		{
			ans++;
			now_place = sentence.find(word, now_place + 1);
		}
		printf("%d %d\n", ans, place);
	}
 
	return 0;
}
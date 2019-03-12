#include <bits/stdc++.h>
using namespace std;

string word;
string sentence;
int ans = 0, plc = -1;

void to_lower(string &str)
{
	for (unsigned int i = 0; i < str.size(); i++)
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
	to_lower(word);
	to_lower(sentence);

	#ifdef TEWILOCAL
		cout<<word<<endl<<sentence<<endl;
	#endif

	for (unsigned int i = 0; i < sentence.size(); i++)
	{
		if (sentence[i] == word[0])
		{
			bool flag = true;
			for (unsigned int j = 0; j < word.size(); j++)
			{
				if (sentence[i + j] != word[j])
				{
					flag =false;
					break;
				}
			}
			if (flag && !isalpha(sentence[i + word.size() - 1]))
			{
				ans++;
				if (plc == -1)
				{
					plc = i;
				}
			}
		}
	}

	plc == -1? printf("%d\n", plc): printf("%d %d\n", ans, plc);

	return 0;
}

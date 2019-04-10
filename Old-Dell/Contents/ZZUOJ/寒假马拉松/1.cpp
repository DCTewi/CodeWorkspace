#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<char, string> data;
string str;

string getFrom(int l)
{
	string ans;
	for (int i = l; i < str.size(); i++)
	{
		if (!isdigit(str[i])) break;
		ans += str[i];
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	getline(cin, str);
	for (int i = 1; i < str.size() - 1; i++)
	{
		if (str[i] == '=')
		{
			data[str[i - 1]] = getFrom(i + 1);
		}
	}

	for (auto it : data)
	{
		cout<<(it.first)<<"="<<(it.second)<<";"<<endl;
	}
	return 0;
}
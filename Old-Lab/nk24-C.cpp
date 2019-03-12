#include <bits/stdc++.h>
using namespace std;

map<char, vector<int> > place;
string data;
int n, m;

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &m);
	cin>>data;

	for (int i = 0; i < data.size(); i++)
	{
		place[data[i]].push_back(i + 1);
	}

	for (int i = 0; i < m; i++)
	{
		char color; int times;
		cin>>color>>times;
		if (place[color].size() < times)
		{
			printf("-1\n");
		}
		else 
		{
			printf("%d\n", place[color][times - 1]);
		}
	}
	return 0;
}
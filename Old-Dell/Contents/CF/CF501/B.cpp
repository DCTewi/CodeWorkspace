#include <bits/stdc++.h>
using namespace std;

vector<int> adata[30], bdata[30];
int step[1e5 + 5], top = 0;

bool undone()
{
	for (int i = 0; i < 27; i++)
	for (int s = 0; s < adata[i].size(); s++)
	{
		if (adata[i][s] != bdata[i][s])
		{
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int n; cin>>n;
	string a, b; cin>>a>>b;
	if (a.size() != b.size())
	{
		puts("-1");
	}
	else
	{
		for (int i = 0; i < a.size(); i++)
		{
			adata[a[i] - 'a'].push_back(i);
		}
		for (int i = 0; i < b.size(); i++)
		{
			bdata[b[i] - 'a'].push_back(i);
		}
		for (int i = 0; i < 27; i++)
		{
			if (adata[i].size() != bdata[i].size())
			{
				puts("-1");
				return 0;
			}
		}
		while (undone())
		{
			for (int i = 0; i < 27; i++)
			{
				for (int s = 0; s < adata[i].size(); s++)
				{
					if (adata[i][s] != bdata[i][s])
					{
						int abss = adata[i][s] - bdata[i][s];
						if (abss > 0)
						{
							for (int j = adata[i][s]; j <= bdata[i][s])
							{
								printf("%d ", j);
								
							}
						}
					}
				}
			}
		}
	}


	return 0;
}

abcdef
123456
abdcef 3
abdecf 4
abdefc 5
abdfec 4
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;
int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];
int ra, rb, ca, cb;

void chengyixia()
{
	for (int i = 0; i < ra; i++)
	{
		for (int j = 0; j < cb; j++)
		{
			for (int k = 0; k < ca; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin>>ra>>ca;
	for (int i = 0; i < ra; i++)
	{
		for (int j = 0; j < ca; j++)
		{
			cin>>a[i][j];
		}
	}
	cin>>rb>>cb;
	for (int i = 0; i < rb; i++)
	{
		for (int  j = 0; j < cb; j++)
		{
			cin>>b[i][j];
		}
	}

	if (ca != rb) cout<<"Error: "<<ca<<" != "<<rb<<endl;
	else
	{
		chengyixia();
		cout<<ra<<" "<<cb<<endl;
		for (int i = 0; i < ra; i++)
		{
			for (int j = 0; j < cb; j++)
			{
				j == cb - 1? cout<<c[i][j]: cout<<c[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	return 0;
}
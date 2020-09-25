#include <bits/stdc++.h>
using namespace std;

vector<int> data;

int main(int argc, char const *argv[])
{
	int n, m;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int tmp; scanf("%d", &tmp);
		data.push_back(tmp);
	}

	for (int i = 0; i < m; i++)
	{
		next_permutation(data.begin(), data.end());
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

char str[1040];
int n;

void maketree(int l, int r)
{
	if (r > l)
	{
		//cout<<l<<" "<<r<<endl;
		maketree(l, (l + r) / 2);
		maketree((l + r + 1) / 2, r);

	}
		int B = 1, I = 1;
		for (int i = 0; i <= r - l; i++)
		{
			if (str[l + i] == '1') B = 0;
			else if (str[l + i] == '0') I = 0;
		}
		if (B)
		{
			printf("B");
		}
		else if (I)
		{
			printf("I");
		}
		else
		{
			printf("F");
		}

}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	scanf("%s", str);

	maketree(0, (1<<n) - 1);

	return 0;
}
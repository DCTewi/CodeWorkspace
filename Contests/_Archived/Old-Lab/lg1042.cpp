#include <bits/stdc++.h>
using namespace std;

const int MAX = 7e4 + 5;
char record[MAX];
int top = 0;

void printScore(int wonscore)
{
	int sco_my = 0, sco_ene = 0;
	if (top == 0)
	{
		printf("0:0\n");
	}
	else
	{
		for (int i = 0; i < top; i++)
		{
			if (record[i] == 'W') sco_my++;
			else if (record[i] == 'L') sco_ene++;

			if (i == top - 1)
			{
				printf("%d:%d\n", sco_my, sco_ene);
				if (sco_my == wonscore || sco_ene == wonscore)
				{
					printf("0:0\n");
				}
			}
			else if (sco_my >= wonscore || sco_ene >= wonscore)
			{
				if (sco_my - sco_ene >= 2 || sco_ene - sco_my >= 2)
				{
					printf("%d:%d\n", sco_my, sco_ene);
					sco_my = 0;
					sco_ene = 0;
				}
				else continue;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	char now = getchar();
	while(now != 'E')
	{
		record[top++] = now;
		now = getchar();
	}

	printScore(11);
	printf("\n");
	printScore(21);

	return 0;
}
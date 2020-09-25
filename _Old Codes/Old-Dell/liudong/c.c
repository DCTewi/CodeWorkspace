/**
 *	利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间的用B表示，60分以下的用C表示；
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	
	int data[n + 5];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (data[i] >= 90)
		{
			puts("A");
		}
		else if (data[i] >= 60)
		{
			puts("B");
		}
		else
		{
			puts("C");
		}
	}
	return 0;
}
/**
 *	用键盘输入‘n’（整数）,然后根据 n 的值，输出n*n乘法口诀表,  如9 x 9乘法口诀表;
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int n; scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", i, j, i * j);
		}
		printf("\n");
	}
	
	return 0;
}
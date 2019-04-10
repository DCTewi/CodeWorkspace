/**
 *	从键盘输入一个字符串，输出其中数字，大写字母，小写字母，其他字符个数；
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int nDigit = 0, nUp = 0, nLow = 0, nOther = 0;
	char ch = getchar();
	while (ch != '\n')
	{
		if (ch >= '0' & ch <= '9')
		{
			nDigit++;
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			nUp++;
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			nLow++;
		}
		else
		{
			nOther++;
		}
		ch = getchar();
	}

	printf("Digit:%d, Upcase:%d, Lowcase:%d, Other:%d\n", nDigit, nUp, nLow, nOther);

	return 0;
}
/**
 *	利用嵌套递归和函数调用模拟汉诺塔的解题过程并输出圆盘数为 64 片时 的 移动顺序;
 */
#include <stdio.h>

void move(char a, char c)
{
	printf("%c -> %c\n", a, c);
}

void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		move(a, c);
	}
	else
	{
		hanoi(n - 1, a, c, b);
		move(a, c);
		hanoi(n - 1, b, a, c);
	}
}

int main(int argc, char const *argv[])
{
	hanoi(64, 'a', 'b', 'c');
	return 0;
}
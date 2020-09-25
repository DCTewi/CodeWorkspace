/**
 *	从键盘输入三个整形数字比较大小，并输出结果，考虑相等情况；
 */
#include <stdio.h>
#include <stdlib.h>

void q_sort(int a[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = a[l];
		while (i < j)
		{
			while (i < j && a[j] >= x) j--;
			if (i < j) a[i++] = a[j];
			
			while (i < j && a[i] < x) i++;
			if (i < j) a[j--] = a[i];
		}
		a[i] = x;

		q_sort(a, l, i - 1);
		q_sort(a, i + 1, r);
	}
}

int main(int argc, char const *argv[])
{
	int a[3];

	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &a[i]);
	}

	q_sort(a, 0, 2);

	for (int i = 0; i < 2; i++)
	{
		printf("%d", a[i]);

		if (a[i] < a[i + 1])
		{
			printf(" < ");
		}
		else 
		{
			printf(" = ");
		}
	}
	printf("%d\n", a[2]);

	return 0;
}

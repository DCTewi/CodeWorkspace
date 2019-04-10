#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX = 4e5 + 5;
char str[MAX];
int num[1000];
int n, k;

int main()
{
    scanf("%d%d%s", &n, &k, str);
    for (int i = 0; i < n; i++)
    {
        num[(int)(str[i] - 'a')]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (k < num[abs(i)])
        {
            num[abs(i)] -= k;
            k = 0;
            break;
        }
        else
        {
            k -= num[abs(i)];
            num[i] = 0;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (!num[ abs((int)(str[i] - 'a'))])
        {
            str[i] = 'N';
        }
        num[abs((int)(str[i] - 'a'))]--;
    }

    for (int i = 0; i < n; i++)
    {
        if (str[i] != 'N')
        {
            printf("%c", str[i]);
        }
    }

    return 0;
}

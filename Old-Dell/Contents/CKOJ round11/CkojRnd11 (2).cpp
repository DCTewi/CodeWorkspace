#include <cstdio>
#include <cstring>

using namespace std;
const int MAX = 2e6 + 5;
char str[MAX];

int main()
{
    scanf("%s", str);
    int len = strlen(str);

    int layer = 0, nxy = 0, flag = 0;

    for (int i = 0; i < len; i++)
    {
        if (nxy == 1 && !layer)
        {
            flag = 1;
            break;
        }
        if (nxy == 2) break;

        if (str[i] == '(') layer++;
        else if (str[i] == ')')layer--;
        else if (str[i] == 'x' || str[i] =='y') nxy++;
    }

    if (flag) return 0 * printf("NO\n");

    return 0 * printf("YES\n");
}

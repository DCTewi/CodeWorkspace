#include <cstdio>
#include <iostream>

using namespace std;
const int MAX = 105;
int num[MAX];
int ans = 0;

int main()
{
    int n; cin>>n;
    for (int i = 0; i < n ; i++)
    {
        int tmp; cin>>tmp;
        num[tmp]++;
        if (num[tmp] > ans)
        {
            ans = num[tmp];
        }
    }

    printf("%d\n", ans);

    return 0;
}

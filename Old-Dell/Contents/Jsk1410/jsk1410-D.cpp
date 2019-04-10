#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n, k;
int timestamp[MAXN], top = 1;
int ans = 1;
int zeroinone = 0;

int getTop(int waiting)
{
    if (waiting == 0)
    {
        zeroinone = 1;
        #ifdef TEWILOCAL
        cout<<"0 -> 1"<<endl;
        #endif // TEWILOCAL
        return top = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if ((!timestamp[i] && (zeroinone && i != 1)) || waiting - timestamp[i] >= 1e3)
        {
            #ifdef TEWILOCAL
            cout<<waiting<<" -> "<<i<<endl;
            #endif // TEWILOCAL

            return top = i;
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        timestamp[getTop(tmp)] = tmp;

        if (top > ans)
        {
            ans++;
            #ifdef TEWILOCAL
            cout<<"ans => "<<ans<<endl;
            #endif // TEWILOCAL
        }
    }

    printf("%d\n", ans % k? ans / k + 1: ans / k);

    return 0;
}

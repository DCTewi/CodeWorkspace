# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
ll a[MAXN], ans[MAXN];//, sum[MAXN];
int main()
{
    int N, M;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= N; i++)
    {
        ans[i] = ans[i - 1] ^ a[i];
    }
    for (int M = 1; M <= N; M++){
        if(ans[M]==0) printf("0\n");
        else{
            ll sum=0;
            for(int i=1;i<=M;i++){
                if((ans[M]^a[i])<a[i]){//a[i]-ans^(a[i])为具体方案
                    sum++;
                }
            }

            printf("%lld\n",sum);//输出方案数
        }
    }
    return 0;
}
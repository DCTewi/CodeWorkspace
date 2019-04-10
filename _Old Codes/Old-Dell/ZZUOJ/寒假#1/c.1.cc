#include<cstdio>
#include<cstring>
int main()
{
    int t,n,j,k,i,count;
    int a[32];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(a,-1,sizeof(a));
        j=0;
        count=0;
        i=n;
        while(i)
        {
            a[j]=i%2;
            if(a[j]==0)
            {
                count++;
            }
             if(a[j]==1)
             {
                 count++;
                 break;
             }
            i/=2;
            j++;
        }
        printf("%d\n",count);
    }
    return 0;
}
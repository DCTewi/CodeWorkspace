#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3e5+5;
int n,a[N],b[N],c[N];long long k;
int main(){
    scanf("%d%I64d",&n,&k);
    for(int i=1,x;i<=n;++i)scanf("%d",&x),a[x]=i-1-n,b[i]=n;
    for(int i=1,x;i<=n;++i){
        scanf("%d",&x);
        if(x-1<=k)b[x]=0,k-=x-1;
        else{
            for(int j=1;j<x;++j)c[j]=a[j];
            sort(c+1,c+x);
            b[x]=-c[k+1];break;
        }
    }
    puts("Yes");
    for(int i=1;i<=n;++i)printf("%d ",a[i]);puts("");
    for(int i=1;i<=n;++i)printf("%d ",b[i]);puts("");
    return 0;
}

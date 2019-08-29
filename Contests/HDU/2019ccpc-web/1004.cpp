#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1333331,inv2=500000004,inv6=166666668;
const LL MOD=1e9+7;
LL a,b,phi[1000010];
int p[100010],cnt=0,i,tot;
bool v[1000010];
unordered_map<int,int> res;
void Get_Prime(){
    for(phi[1]=1,i=2;i<=1000000;i++){
        if(!v[i])p[tot++]=i,phi[i]=i-1;
        for(int j=0;i*p[j]<=5000000&&j<tot;j++){
            v[i*p[j]]=1;
            if(i%p[j]){
                phi[i*p[j]]=phi[i]*(p[j]-1);
            }else{
                phi[i*p[j]]=phi[i]*p[j];
                break;
            }
        }
    }for(int i=2;i<=1000000;++i)phi[i]=(phi[i-1]+1ll*i*phi[i]%MOD)%MOD;
}
LL phi_sum(LL n){
    if(n<=1000000)return phi[n];
    if(res.count(n)) return res[n];
    LL la,A=0;
    for(LL i=2;i<=n;i=la+1){
        LL now=n/i; la=n/now;
        (A+=(la-i+1)%MOD*(la+i)%mod*inv2%mod*phi_sum(n/i)%MOD)%=MOD;
    }A=((n%MOD)*(n%MOD+1)%MOD*(2*n%mod+1)%mod*inv6%MOD-A+MOD)%MOD;
return res[n]=A;
}
int main(){
//    scanf("%lld",&a);
    Get_Prime();
//    printf("%lld\n",phi_sum(a));
    int T;scanf("%d",&T);
    while(T--){
        LL n,a,b;scanf("%lld%lld%lld",&n,&a,&b);
        LL ans=phi_sum(n);
        printf("%lld\n",(ans-1)*inv2%MOD);
    }
    return 0;
}


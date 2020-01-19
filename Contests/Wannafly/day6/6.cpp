#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod =998244353;
const ll st2=116195171;
const int maxn=400010;

int rev[maxn];
ll x[maxn],y[maxn];

ll mypow(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}

void ntt(ll x[],int len,int on){
    for(int i=0;i<len;i++)rev[i]=(i&1)*(len>>1)+(rev[i>>1]>>1);
    for(int i=0;i<len;i++)if(i<rev[i])swap(x[i],x[rev[i]]);

    for(int i=2;i<=len;i<<=1){
        ll gn=mypow(3,(mod-1)/i);
        int d=i>>1;
        for(int j=0;j<len;j+=i){
            ll g=1;
            for(int k=j;k<j+d;k++){
                ll a=x[k];
                ll b=g*x[k+d]%mod;
                (x[k]=a+b)<mod?0:x[k]-=mod;
                (x[k+d]=a-b)>=0?0:x[k+d]+=mod;
                g=gn*g%mod;
            }
        }
    }
    if(on==-1){
        reverse(x+1,x+len);
        int inv=mypow(len,mod-2);
        for(int i=0;i<len;i++)x[i]=x[i]*inv%mod;
    }
}

void work(ll x[],int m,ll y[],int n){

    int len=1;
    while(len<=m+n)len<<=1;
    ntt(x,len,1);ntt(y,len,1);
    for(int i=0;i<len;i++)x[i]=x[i]*y[i]%mod;
    ntt(x,len,-1);ntt(y,len,-1);

}

int f[maxn];
int main(){
    {
        int n;cin>>n;
        for(int i=0;i<=4*n;i++)f[i]=x[i]=y[i]=0;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for(int i=1;i<=n;i++)f[a[i]]++;

        ll inv=mypow(st2,mod-2);

        for(int i=0;i<=n;i++){
            x[i]=mypow(inv,1ll*i*i);
        }

        for(int i=1;i<=n;i++){
            y[i]=i*mypow(st2,1ll*i*i)%mod*f[i]%mod;
        }

        work(x,n,y,n);

        ll ans=0;
        for(int i=1;i<=n;i++){
            ans+=y[i]*x[i]%mod;
        }
        ans*=2;

        for(int i=1;i<=n;i++){
            ans-=1ll*i*i%mod*mypow(2,1ll*i*i)%mod*f[i]%mod*f[i]%mod;
        }
        (ans%=mod)<0?ans+=mod:ans;
        cout<<ans<<endl;
    }
}

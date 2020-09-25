#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<iostream>
using namespace std;

#define LL long long
LL n;
#define maxs 80
LL fac[maxs],num[maxs],lf=0;
LL mul(LL a,LL b,LL p)
{
    LL tmp=a,ans=0;
    while (b) {if (b&1) ans=(ans+tmp)%p;tmp=(tmp+tmp)%p;b>>=1;}
    return ans;
}
LL random(LL x) {return (LL)((double)rand()/RAND_MAX*(x-1)+0.5);}
LL f(LL x,LL c,LL p) {return (mul(x,x,p)+c)%p;}
LL gcd(LL a,LL b) {if (a<b) return gcd(b,a);return b?gcd(b,a%b):a;}
LL play(LL x,LL c)
{
    LL a=random(x-1)+1,b=f(a,c,x),i=1,k=2;
    if (a==b) return x;
    while (++i)
    {
        LL sig=gcd(fabs(a-b),x);
        if (sig>1 && sig<x) return sig;
        b=f(b,c,x);
        if (a==b) return x;
        if (i==k) a=b,k<<=1;
    }
}
LL pow_mod(LL a,LL b,LL p)
{
    LL tmp=a,ans=1;
    while (b) {if (b&1) ans=mul(ans,tmp,p);tmp=mul(tmp,tmp,p);b>>=1;}
    return ans;
}
bool is_prime(LL x)
{
    LL num=x-1,k=0;while (!(num&1)) num>>=1,k++;
    for (int i=1;i<=20;i++)
    {
        LL t=random(x-2)+1,jud=pow_mod(t,num,x),now=jud;
        for (int j=1;j<=k;j++)
        {
            jud=mul(jud,jud,x);
            if (jud==1 && now!=1 && now!=x-1) return 0;
            now=jud;
        }
        if (jud!=1) return 0;
    }
    return 1;
}
void rho(LL x,LL c)
{
    if (x==1) return;
    if (is_prime(x)) {fac[++lf]=x;return;}
    LL p=x,tmp=c;
    while (p==x) p=play(x,tmp--);
    rho(p,c);rho(x/p,c);
}
int main()
{
    srand(time(NULL));
    scanf("%lld",&n);
    memset(fac,0,sizeof(fac));
    rho(n,120);sort(fac+1,fac+1+lf);num[1]=1;LL nlf=1;
    for (int i=2;i<=lf;i++)
        if (fac[i-1]==fac[i]) num[nlf]++;
        else num[++nlf]=1,fac[nlf]=fac[i];
    lf=nlf;
    for (int i=1;i<lf;i++) printf("%lld^%lld*",fac[i],num[i]);printf("%lld^%lld\n",fac[lf],num[lf]);
    return 0;
}

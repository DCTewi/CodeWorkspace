#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const int NUM=10;
ll t,f[100];
inline ll mul_mod(ll a,ll b,ll n)
{
    return a * b % n;
}
ll pow_mod(ll a,ll b,ll n)
{
    a=a%n;
    ll s=1;
    while(b)
    {
        if(b&1)
            s=mul_mod(s,a,n);
        a=mul_mod(a,a,n);
        b=b>>1;
    }
    return s;
}
bool check(ll a,ll n,ll r,ll s)
{
    ll ans,p,i;
    ans=pow_mod(a,r,n);
    p=ans;
    for(i=1;i<=s;i++)
    {
        ans=mul_mod(ans,ans,n);
        if(ans==1&&p!=1&&p!=n-1)return true;
        p=ans;
    }
    if(ans!=1)return true;
    return false;
}
bool Miller_Rabin(ll n)
{
    if(n<2)return false;
    if(n==2)return true;
    if(!(n&1))return false;
    ll i,r,s,a;
    r=n-1;s=0;
    while(!(r&1)){r=r>>1;s++;}
    for(i=0;i<NUM;i++)
    {
        a=rand()%(n-1)+1;
        if(check(a,n,r,s))
            return false;
    }
    return true;
}
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
ll Pollard_rho(ll n,ll c)
{
    ll i=1,j,k=2,x,y,d,p;
    x=rand()%n;
    y=x;
    while(true)
    {
        i++;
        x=(mul_mod(x,x,n)+c)%n;
        if(y==x)return n;
        if(y>x)p=y-x;
        else p=x-y;
        d=gcd(p,n);
        if(d!=1&&d!=n)return d;
        if(i==k)
        {
            y=x;
            k+=k;
        }
    }
}
void _find(ll n)
{
    if(Miller_Rabin(n))
    {
        f[t++]=n;
        return;
    }
    ll p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
    _find(p);
    _find(n/p);
}
ll solve(ll n)
{
    if(n == 1) {
        return 0;
    }
    if(Miller_Rabin(n)){
        return 1;
    }
    t=0;
    _find(n);
    map<ll,ll> ma;
    for(int i=0;i<t;i++) ma[f[i]]++;
    ll ans=1; for(auto it:ma) ans*=it.second+1;
    return ans;
}
ll com2(ll x)
{
    ll tmp = 0;
    while(x%2==0)
    {
        ++tmp, x/=2;
    }
    return tmp;
}
int main()
{
    srand(time(NULL));
//   freopen("in.txt","r",stdin);
    int T; scanf("%d",&T);
    while(T--)
    {
        int n; scanf("%d",&n);
        ll ans = 0;
        for(int i=1;i<=n;++i)
        {
            ll t; scanf("%lld",&t);
            ll qq = solve(t); if(qq>1) --qq;
            ll tmp = com2(t); ll pp = qq - tmp; if(tmp) ++pp;
            ans ^= pp;
        }
        if(ans) printf("W"); else printf("L");
        putchar('\n');
    }
    return 0;
}

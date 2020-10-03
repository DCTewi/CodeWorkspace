#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e3+5;
struct Vec {ll x,y;} p[maxn] , s[maxn]; int top;
ll dis(Vec a,Vec b) { return  (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) ; }
ll mul(Vec b,Vec c,Vec a) { return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x) ; }
bool cmp(Vec a,Vec b)
{
	if( mul(a,b,p[0]) == 0 ) return dis(a,p[0]) < dis(b,p[0]);
	else return mul(a,b,p[0])>0;
}
ll area(Vec a,Vec b)
{
    return  a.x*b.y - a.y*b.x   ;
}
int main()
{
 //   freopen("in.txt","r",stdin);
    int n; scanf("%d",&n);
    ll res = 0 , oarea = 0;
    for(int i=1;i<=n;++i)
    {
        int P; scanf("%d",&P);
        /*
        int k = 0;
        for(int j=0;j<P;++j) 
        {
            scanf("%lld%lld",&p[j].x,&p[j].y);
            if(p[j].y<p[k].y) k = j;
        }
        if(k!=0) swap(p[0],p[k]);
        sort(p+1,p+P,cmp);
        s[0] = p[0]  ,s[1] = p[1] , s[2] = p[2] , top = 2;
        for(int j=3;j<P;++j)
        {
            while(top && mul(p[j],s[top],s[top-1])>=0 ) oarea += area({p[j].x-s[top].x,p[j].y-s[top].y},{s[top-1].x-s[top].x,s[top-1].y-s[top].y}) , --top;
		    s[++top] = p[j];
        }
        for(int j=2;j<=top;++j) res += area({s[j-1].x-s[0].x,s[j-1].y-s[0].y},{s[j].x-s[0].x,s[j].y-s[0].y});
        */
       ll ta = 0; scanf("%lld%lld",&p[0].x,&p[0].y);
       for(int j=1;j<P;++j)
       {
           scanf("%lld%lld",&p[j].x,&p[j].y); 
            if(j>1) ta += area({p[j-1].x-p[0].x,p[j-1].y-p[0].y},{p[j].x-p[0].x,p[j].y-p[0].y});
       }
       res += abs(ta);
    }
    printf("%lld",((res)/2));
    return 0;
}
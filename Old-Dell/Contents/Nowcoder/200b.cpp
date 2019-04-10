#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=100000+10;

int n,m;

struct Node
{
    int l,r;
    int sum1,sum2,sum3;
    int add,mul,alt;
    void Update_Alt(int x)
    {
        sum1 = (r-l+1) * x;
        sum2 = (r-l+1) * x * x;
        sum3 = (r-l+1) * x * x * x;
        alt=x;
        add=0;
        mul=1;
    }
    void Update_Mul(int x)
    {
        sum1 = sum1 * x;
        sum2 = sum2 * x * x;
        sum3 = sum3 * x * x * x;
        mul = mul * x;
        add = add * x;
    }
    void Update_Add(int x)
    {
        sum3 = ( sum3 + 3*x*sum2 + 3*x*x*sum1 + (r-l+1)*x*x*x );
        sum2 = ( sum2 + 2*x*sum1 + (r-l+1)*x*x );
        sum1 = ( sum1 + (r-l+1)*x );
        add=(add+x);
    }
}node[4*maxn];
void Pushdown(int root)
{
    int ls=root*2, rs=root*2+1;
    if(node[root].alt!=0)
    {
        node[ls].Update_Alt(node[root].alt);
        node[rs].Update_Alt(node[root].alt);
        node[root].alt=0;
    }
    if(node[root].mul!=1)
    {
        node[ls].Update_Mul(node[root].mul);
        node[rs].Update_Mul(node[root].mul);
        node[root].mul=1;
    }
    if(node[root].add!=0)
    {
        node[ls].Update_Add(node[root].add);
        node[rs].Update_Add(node[root].add);
        node[root].add=0;
    }
}
void Pushup(int root)
{
    int ls=root*2, rs=root*2+1;
    node[root].sum1=(node[ls].sum1+node[rs].sum1);
    node[root].sum2=(node[ls].sum2+node[rs].sum2);
    node[root].sum3=(node[ls].sum3+node[rs].sum3);
}
void Build(int root,int l,int r) //对区间[l,r]建树
{
    if(l>r) return;
    node[root].l=l; node[root].r=r;
    node[root].sum1=0;
    node[root].sum2=0;
    node[root].sum3=0;
    node[root].alt=0;
    node[root].add=0;
    node[root].mul=1;

    if(l<r)
    {
        int mid=l+(r-l)/2;
        Build(root*2,l,mid);
        Build(root*2+1,mid+1,r);
        Pushup(root);
    }
}
void Alt(int root,int st,int ed,int val) //区间[st,ed]全部改成val
{
    if(st>node[root].r || ed<node[root].l) return;
    if(st<=node[root].l && node[root].r<=ed) node[root].Update_Alt(val);
    else
    {
        Pushdown(root);
        Alt(root*2,st,ed,val);
        Alt(root*2+1,st,ed,val);
        Pushup(root);
    }
}
void Mul(int root,int st,int ed,int val) //区间[st,ed]全部加上val
{
    if(st>node[root].r || ed<node[root].l) return;
    if(st<=node[root].l && node[root].r<=ed) node[root].Update_Mul(val);
    else
    {
        Pushdown(root);
        Mul(root*2,st,ed,val);
        Mul(root*2+1,st,ed,val);
        Pushup(root);
    }
}
void Add(int root,int st,int ed,int val) //区间[st,ed]全部加上val
{
    if(st>node[root].r || ed<node[root].l) return;
    if(st<=node[root].l && node[root].r<=ed) node[root].Update_Add(val);
    else
    {
        Pushdown(root);
        Add(root*2,st,ed,val);
        Add(root*2+1,st,ed,val);
        Pushup(root);
    }
}
int Query(int root,int st,int ed,int p) //查询区间[st,ed]的p次方和
{
    if(st>node[root].r || ed<node[root].l) return 0;
    if(st<=node[root].l && node[root].r<=ed)
    {
        if(p==1) return node[root].sum1;
        if(p==2) return node[root].sum2;
        if(p==3) return node[root].sum3;
    }
    else
    {
        Pushdown(root);
        int ls=Query(root*2,st,ed,p);
        int rs=Query(root*2+1,st,ed,p);
        Pushup(root);
        return (ls+rs);
    }
    return 0;
}

signed main()
{
    while (~scanf("%lld%lld",&n,&m) && n && m)
    {
        Build(1,1,n);
        for (int i = 1; i <= n; i++)
        {
            int no; scanf("%lld", &no);
            Add(1, i, i, no);
        }
        for(int i=1;i<=m;i++)
        {
            int op; scanf("%lld",&op);
            if(op==4)
            {
                int x,y,k;
                scanf("%lld%lld%lld",&x,&y,&k);
                Add(1,x,y,k);
            }
            if(op==3)
            {
                int x,y,k;
                scanf("%lld%lld%lld",&x,&y,&k);
                Mul(1,x,y,k);
            }
            if(op==2)
            {
                int l,r;
                scanf("%lld%lld",&l,&r);
                printf("%lld\n",Query(1,l,r,2));
            }
            if(op==1)
            {
                int l,r;
                scanf("%lld%lld",&l,&r);
                printf("%lld\n",Query(1,l,r,1));
            }
        }
    }
}
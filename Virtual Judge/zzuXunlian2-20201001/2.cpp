#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main()
{
    ll n1,n2,n12; scanf("%lld%lld%lld",&n1,&n2,&n12);
    printf("%lld",(n1+1)*(n2+1)/(n12+1)-1);
    return 0;
}
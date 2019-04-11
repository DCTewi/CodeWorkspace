#include<bits/stdc++.h>
using namespace std;
typedef unsigned  long long LL;
//int t[10000];
LL F(LL n){
    LL cnt = 0;
    for(int i = 1;i <=  63; ++i){
        LL t = (1<<i)-1;
        if(t <= n) cnt++;
        if(t > n) break;
        for(int j = 1;j <= 63; ++j){
                LL tt = t;
                LL len = i;
                for(;tt <= n;)
                {
                    if(len + j >= 64) break;
                    tt <<= j,len += j; 
                    if(tt <= n)
                        cnt++;
                    if(len + i >= 64) break;
                    tt <<= i,len += i;
                    tt += t;
                    if(tt <= n)
                        cnt++;
//                  cout<<tt<<endl;
                }
        }
    }
    return cnt;
}
int main() {
    //'/cout<<(1ULL<<63)-1<<endl;
//  cout<<F(1000)<<endl;
    LL a,b;
    cin>>a>>b;
    if(a == 0)
      a = 0;
    else
      a = F(a-1);
    if(b == 0)
      b = 0;
    else
       b = F(b);
       
    cout<<b-a<<endl;

}

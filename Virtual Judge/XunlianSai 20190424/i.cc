#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct cir {
    LL x,y,r;
    LL inx;

    inline bool ins(cir c2) {
        return (c2.r + r)*(c2.r + r) <= (x-c2.x)*(x-c2.x)+(y-c2.y)*(y-c2.y);
    }
} cs[1005];
int f[1005];
int lm[1005],rm[1005];
int cnt = 0;

LL t;
LL n,w,h;

int root(int x) {
    return f[x]==x?x:f[x] = root(f[x]);
}
void join(int a, int b) {
    int ra = root(a), rb = root(b);
    if (ra!=rb) {
        lm[ra] = min(lm[rb], lm[ra]);
        rm[ra] = max(rm[rb], rm[ra]);
        f[rb]=ra;
    }
}



int main() {
    cin >> t;
    while(t--) {
        cin >> n >> w >> h;
        for (int i=0; i<1005; ++i) f[i] = i;
        cnt = 0;

        for (int w=0; w<n; ++w) {
            cin >> cs[cnt].x >> cs[cnt].y >> cs[cnt].r;
            cs[cnt].inx = cnt;
            lm[cnt] = cs[cnt].x-cs[cnt].r;rm[cnt]=cs[cnt].x+cs[cnt].r;
            for (int i=0;i<cnt; ++i) {
                if(cs[cnt+1].ins(cs[i])) {
                    join(cnt+1, i);
                }
            }
            ++cnt;
        }
        int ans = 0;
        for (int i=0; i<1005; ++i) {
            if (f[i]==i) {
                if (lm[i]<=0 && rm[i]>=w) ++ans;
            }
        }
        cout << ans << endl;
    }
}



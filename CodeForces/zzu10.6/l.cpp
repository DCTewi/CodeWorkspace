#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n;
LL maxen;



LL fpow(LL a, LL k)
{
	if (!k) return 1;

	LL ans = 1;
	while (k)
	{
		if (k & 1) ans = ans * a;
		a = a * a;
		k >>= 1;
	}
	return ans;
}

LL f(LL a, LL m, LL t) {
    return fpow(a,t-m)*fpow(a+1,m);
}


//solve a^(t-m)*(a+1)^t=n for m
LL solve(LL a, LL t) {
    LL l = 0, r=t+1;

    while(r>l) {
        LL m = (r+l)/2;
        LL tmp = f(a,m,t);
        if (f(a,m,t)>=n) r=m;
        else l=m+1;
    }

    if (f(a,l,t)==n) return t-l;
    else return -1;
}



struct ANS {
    int a, m, t;
    ANS(int a=0, int m=0, int t=0):a(a),m(m),t(t){}
};

vector<ANS> ans;

bool check(LL x)
{
    return bitset<64>(x).count()==1;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    if (check(n)) return 0*puts("-1");



    maxen = (log(n)/log(2));
    for (int i=1; i<=maxen; ++i) {
        LL averf = pow(n, 1.0L/i);
        LL inx = solve(averf, i);
        if (inx!=-1) {
            ans.emplace_back(ANS(averf,inx,i));
        }
    }

    cout << ans.size() << '\n';
    for (int i=0; i<ans.size(); ++i) {
        cout << ans[i].t << ' ';
        for (int j=0; j<ans[i].m; ++j) cout << ans[i].a << ' ';
        for (int j=0; j<ans[i].t-ans[i].m; ++j) cout << ans[i].a+1 << ' ';
        cout << '\n';
    }

}

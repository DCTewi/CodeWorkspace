#include<bits/stdc++.h>
using namespace std;

struct player {
    string name;
    double t1, t2;
}ps[505];
int n;

int aid[5];
double gett2(int p1) {
    double t = 0;
    for (int i=0, cnt = 0; cnt < 3 && i<n; ++i) {
        if(i != p1) t+=ps[i].t2, aid[cnt++] = i;
    }
    return t;
}


int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> ps[i].name >> ps[i].t1 >> ps[i].t2;
    }
    sort(ps,ps+n,[](player &p1, player &p2){return p1.t2 < p2.t2;});

    double ans = 1e10; int aid1;
    for (int i=0; i<n; ++i) {
        if (ps[i].t1 + gett2(i) < ans) {
            ans = ps[i].t1 + gett2(i);
            aid1= i;
        }
    }
    gett2(aid1);

    cout << ans << '\n' << ps[aid1].name << '\n';
    for (int i=0; i<3; ++i) cout << ps[aid[i]].name << '\n';
}

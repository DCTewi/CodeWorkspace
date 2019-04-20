#include <bits/stdc++.h>
using namespace std;

int cf[100000007], mat[80], zn[80];
int r,c;
int n,q;
inline int &v(int rr, int cc, int*arr){
    return arr[rr*(c+1)+cc];

}

void dp() {
    for (int i=1; i<=r; ++i) {
        for (int j=1; j<=c; ++j) {
            v(i,j,zn) = v(i, j-1, zn)+v(i-1,j,zn)-v(i-1,j-1,zn)+(v(i,j,mat)==0);
        }
    }
}

void apply() {
    for (int i=1; i<=r; ++i) {
        for (int j=1; j<=c; ++j) {
            v(i,j,mat) = v(i-1,j,mat)+v(i,j-1,mat)-v(i-1,j-1,mat) + v(i-1,j-1,cf);
        }
    }

}



int main()
{
    ios::sync_with_stdio(0);
    while(cin >> r) {
        int ra,ca,rb,cb;
        memset(cf,0,sizeof cf);
        memset(zn,0,sizeof zn);
        cin >> c >> n;
        for (int i=0; i<n; ++i) {
            cin >> ca >> ra >> cb >> rb;
            v(ra-1,ca-1,cf)++;
            v(rb,cb,cf)++;
            v(ra-1,cb,cf)--;
            v(rb,ca-1,cf)--;
        }
        apply();
        dp();




        cin >> q;
        for (int i=0; i<q; ++i) {
            cin >> ca >> ra >> cb >> rb;


            if (v(rb,cb,zn)==(   v(ra-1, cb,zn)+   v(rb, ca-1, zn)-   v(ra-1,ca-1,zn)    )   ) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
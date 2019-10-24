#include<bits/stdc++.h>
using namespace std;

int n, m, t, pe;
int sol[100005], p[100006];
set<int> dl;


inline bool gr(int t1, int t2) {
    if (sol[t1]!=sol[t2]) return sol[t1] > sol[t2];
    else return p[t1] < p[t2];
}


int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    while(m--) {
        cin >> t >> pe;
        sol[t]++;p[t]+=pe;
        if (t==1) {
            for (auto it = dl.begin(); it!=dl.end();) {
                if (!gr(*it,1)) dl.erase(it++);
                else ++it;
            }
        } else {
            if (gr(t, 1)) dl.emplace(t);
        }
        cout << dl.size()+1 << '\n';
    }
}


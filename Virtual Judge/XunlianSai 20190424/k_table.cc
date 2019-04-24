#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

string s;


int chk(int n, int* sp) {
    vector<int> v;
    int sum = 0;
    for (int i=0; i<n-1; ++i) {
        sum += s[i]-'0';
        if (sp[i]) v.push_back(sum), sum=0;
    }
    v.push_back(sum+s[n-1]-'0');
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));cout << endl;
    int nn = v.size();
    for (int i=0; i<=nn/2; ++i) {
        if (v[i]!=v[nn-i]) return 0;
    }
    return 1;
}

int main() {
    while(1) {
        getline(cin,s);
        int n = s.length();
        int sp[n];
        int cnt = 0;
        for (int i=0; i<n; ++i) {
            memset(sp,0,sizeof sp);
            for (int j=0;j<i;++j) sp[j]=1;
            next_permutation(sp,sp+n-1);
            do {
                if (chk(n, sp)) ++cnt;
                //copy(sp,sp+n-1,ostream_iterator<int>(cout," "));
                //cout << endl;
            }while(next_permutation(sp,sp+n-1));
        }
        cout << cnt << endl;

    }
}



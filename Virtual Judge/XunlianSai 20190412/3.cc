//D
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
string s;
const int cnt = 12;
string src[] = {"a$","i$","y$","l$","n$","ne$","o$","r$","t$","u$","v$","w$"};
string dst[] = {"as", "ios", "ios", "les", "anes", "anes", "os", "res", "tas", "us", "ves", "was"};

int main(){
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> s;
        for (int i=0; i<cnt; ++i) {
            regex reg(src[i]);
            if (regex_search(s,reg)) {
                cout << regex_replace(s,reg,dst[i]) << endl;
                goto nex;
            }
        }
        cout << s << "us\n";

        nex:;
    }

    return 0;
}
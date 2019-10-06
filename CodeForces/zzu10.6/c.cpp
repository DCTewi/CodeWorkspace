#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

char s[1000006];
int n;
int near[128][128];
int sel[128], ans[128], ansv=0;
bool isv[128];
vector<char> cs;



int calc() {
    int ans = 0;
    for (char c='a'; c<='z'; ++c)
        for (char nc='a'; nc<='z'; ++nc)
            if (sel[c] && !sel[nc] && !isv[c] && !isv[nc])
                ans += near[c][nc];
    return ans;
}

void dfs(int d) {
    if (d<cs.size()) {
        sel[cs[d]] = 0;
        dfs(d+1);
        sel[cs[d]] = 1;
        dfs(d+1);
    } else {
        int tmp = calc();
        if (tmp > ansv) {
            for (char c='a'; c<='z'; ++c) ans[c] = sel[c];
            ansv = tmp;
        }
    }
}


int main() {
    freopen("consonant.in", "r", stdin);
    freopen("consonant.out", "w", stdout);

    isv['a'] = isv['e'] = isv['i'] = isv['o'] = isv['u'] = isv['w'] = isv['y'] = 1;
    for (char i='a'; i<='z'; ++i) if (!isv[i]) cs.emplace_back(i);
    scanf("%s", s+1);
    n = strlen(s+1);
    for (int i=1; i<=n; ++i) {
        ++near[s[i]][s[i-1]];
        ++near[s[i]][s[i+1]];
    }

    dfs(0);
    for (int i=1; i<=n; ++i)
        if (ans[s[i]]) putchar(s[i]-'a'+'A');
        else putchar(s[i]);

}

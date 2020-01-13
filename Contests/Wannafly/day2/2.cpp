#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
double hars[1000006], stras[1000006];
char s[1000006]; LL n;

inline bool f(char c) {
    return c == 'a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y';
}

int main(){
    scanf("%s", s+1);n = strlen(s+1);
    for (int i=1; i<=n+2; ++i) hars[i] = hars[i-1] + 1.0/i;
    for (int i=1; i<=n; ++i) stras[i] = stras[i-1] + (n+1.0-i)/i;
    double ans = 0;
    for (int i=1; i<=n; ++i) {

        if (f(s[i])) {

            int p = min((LL)i, n+1-i);

            ans += p+stras[n]-stras[n-p]+p*(hars[n-p]-hars[p]);

        }

    }
    printf("%.9f", ans*2 / ((1+n)*n));

    return 0;

}
//B
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
int prf[MAXN], suf[MAXN];
int ans = -9999;

int main()
{
    string a; cin>>a;
    for (int i = 1; i < a.size(); i++)
    {
        prf[i] += prf[i - 1];
        if (a[i] == ':' && a[i - 1] == '(') prf[i]++;
    }
    for (int i = a.size() - 2; i >= 0; i--)
    {
        suf[i] += suf[i + 1];
        if (a[i] == ':' && a[i + 1] == ')') suf[i]++;
    }
    for (int i = 0; i < a.size(); i++)
    {
        ans = max(ans, prf[i] + suf[i + 1] + (a[0] == ':' && a[i + 1] == ')'));
    }
    
    cout<<ans<<endl;

    return 0;
}

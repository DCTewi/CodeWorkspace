#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s; int size; cin>>size>>s;

    string dic = "ACTG";

    int ans = 1<<20;
    for (int i = 0; i < s.size() - 3; i++)
    {
        int ansp = 0;
        for (int j = 0; j < 4; j++)
        {
            ansp += abs(s[i + j] - dic[j]) > 13? 26 - abs(s[i + j] - dic[j]): abs(s[i + j] - dic[j]);
        }
        ans = min(ans, ansp);
    }

    cout<<ans<<"\n";

    return 0;
}

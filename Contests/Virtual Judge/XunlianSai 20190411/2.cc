//D
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;

int main()
{
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; string s;
    cin>>n>>s;
    int now = 0, i = 0, len = s.size();
    for (; i < len; i++)
    {
        if (s[i] == 'M') now++;
        else now--;
        
        if (abs(now) > n)
        {
            if (i + 1 < len && s[i + 1] != s[i])
            {
                s[i] == 'M'? now--: now++;
                i++;
            }
            else
            {
                break;
            }
        }
    }
    
    cout<<i<<endl;
    
    return 0;
}


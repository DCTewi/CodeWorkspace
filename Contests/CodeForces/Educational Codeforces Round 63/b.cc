#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int n; cin>>n;
    string s; cin>>s;

    if ((s[0] == '8' || s[1] == '8') && n == 12) return 0 * puts("YES");

    int nn = n - 11;
    int stp = (nn + 1) / 2, num = 0;
    int dlt = 0;
    int i = 0;
    for (; i < s.size() && dlt < nn / 2; i++)
    {
        if (s[i] != '8') num++;
        else
        {
            dlt++;
        }
    }
    for (; i < s.size(); i++)
    {
        if (s[i] != '8') num++;
        else
        {
            break;
        
        }
    }

    if (dlt < nn / 2) return 0 * puts("NO");
    if (num > stp) return 0 * puts("NO");

    puts("YES");
    return 0;
}
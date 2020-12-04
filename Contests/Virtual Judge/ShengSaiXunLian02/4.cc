//B duipai
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans = 0;

int check(string a, int l)
{
    int len = 0;
    string na;
    for (int i = l; i >= 0; i--)
    {
        if (a[i] == '(') na += ')';
        else if (a[i] == ')') na += '(';
        else na += a[i];
    }
    for (int i = l + 1; i < a.size(); i++)
    {
        na += a[i];
    }
    
    for (int i = 1; i < na.size(); i++)
    {
        if (na[i] == ')' && na[i - 1] == ':')
        {
            len++;
        }
    }
    return len;
}

int checkif(string a, int wanna)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (check(a, i) == wanna)
        {
            return i;
        }
    }
}

int main()
{
    string a; cin>>a;
    
    for (int i = 0; i < a.size(); i++)
    {
        ans = max(ans, check(a, i));
    }
    
    cout<<ans<<endl;
    
    cout<<checkif(a, ans)<<endl;
    
    return 0;
}


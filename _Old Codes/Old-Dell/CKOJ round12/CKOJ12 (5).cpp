#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a, b, c;

ll power (ll base, ll index)
{
    ll ans = 1;
    base %= c;

    while (index)
    {
        if (index & 1) ans = ans * base % c;
        index >>=1;
        base = base * base % c;
    }

    return ans;
}

int main()
{
    int T;cin>>T;
    string A, B;
    while (T--)
    {
        cin>>A>>B>>c;
        for (unsigned int i = 0; i < A.size(); i++)
        {
            a = (a<<3) + (a<<1) + (A[i] - '0');
            a %= c;
        }
        for (unsigned int i = 0; i < B.size(); i++)
        {
            b = (b<<3) + (b<<1) + (B[i] - '0');
            b %= c;
        }
        cout<<a<<" "<<b<<" "<<c<<endl;
        cout<<power(a, b)<<endl;
    }

    return 0;
}

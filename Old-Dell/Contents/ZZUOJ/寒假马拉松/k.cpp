#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n = 0, k, nextt;
string str;

inline ll ch2int(char n)
{
    if (n >= '0' && n <= '9') return n - '0';
    else return n - 'A' + 10;
}

bool check(ll n)
{
    ll ans = 0;
    for (register ll i = n; i != 0; i /= k)
    {
        ans = ans * k + i % k;
    }
    nextt = ans + n;
    return ans == n;	
}

int main(int argc, char const *argv[])
{
    cin>>k>>str;
    for (int i = 0; i < str.size(); i++)
    {
        n = n * k + ch2int(str[i]);
    }
    ll step = 0;
    for (; !check(n) && step <= 30; step++)
    {
        n = nextt;
    }
    step <= 30? cout<<"STEP="<<step<<endl: cout<<"Impossible!"<<endl;

    return 0;
}

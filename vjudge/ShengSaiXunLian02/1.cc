//A
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    
    b += a / 2;
    
    cout<<min(b, c)<<endl;
    
    return 0;
}

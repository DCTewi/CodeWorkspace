//J
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int sum = 0;
    
    while (n--)
    {
        int temp; cin>>temp;
        sum += temp + n;
    }
    
    if (sum % 7)
    {
        puts("no");
    }
    else
    {
        puts("yes");
    }

    return 0;
}


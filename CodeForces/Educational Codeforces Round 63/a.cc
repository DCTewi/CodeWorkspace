#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int n; cin>>n;
    string a;
    cin>>a;

    for (int i = a.size() - 1; i > 0; i--)
    {
        if (a[i] < a[i - 1])
        {
            puts("YES");
            cout<<i<<" "<<i + 1<<"\n";
            return 0;
        }
    }

    puts("NO");

    return 0;
}
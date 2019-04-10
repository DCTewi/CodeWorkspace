#include <bits/stdc++.h>
using namespace std;
string a, b, c;

void replaceall()
{
    string atemp = a;
    for (string::size_type pos = 0; pos != string::npos && pos < a.size(); pos ++)
    {
        if ((pos = atemp.find(b, pos)) != string::npos)
        {
            a.replace(pos, 1, c);
        }
        else break;
    }
}

int main()
{
    int T; cin>>T;
    while(T--)
    {
        int x, y;
        cin>>a>>b>>c>>x>>y;
        for (int i = 0; i < x; i++)
        {
            replaceall();
        }
        cout<<a[y - 1]<<endl;
    }
    return 0;
}

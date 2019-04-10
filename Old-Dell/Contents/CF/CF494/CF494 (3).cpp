#include <iostream>

using namespace std;

int main()
{
    int a, b, x, n;
    cin>>a>>b>>x;

    int flag = a > b? 0: 1;
    while (--x)
    {
        //cout<<"x="<<x<<endl;
        cout<<flag;//<<endl;
        flag? b--: a--;
        //cout<<"a, b="<<a<<" "<<b<<endl;

        flag = !flag;
    }

    int l = flag? b: a;int r = flag? a: b;
    while(l--) cout<<flag;
    while(r--) cout<<!flag;
    cout<<endl;

    return 0;
}

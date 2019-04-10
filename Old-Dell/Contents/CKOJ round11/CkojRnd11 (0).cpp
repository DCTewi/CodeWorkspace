#include <iostream>

using namespace std;

int main()
{
    int y, m, d;
    cin>>y>>m>>d;
    int ans = y - 1999 - 1;
    (m > 6 || (m == 6 && d >= 30))? ans++: 0;

    cout<<ans<<endl;

    return 0;
}

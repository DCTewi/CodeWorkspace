#include <cstdio>
#include <iostream>
////////////////////WRONG///////////////////
using namespace std;
const int MAX = 105;
int a, b, x, n;


int main()
{
    cin>>a>>b>>x;
    n = a + b;
    x -= 1;

    int flag = 0;

    while (a || b)
    {
        cout<<flag;
        if (!flag) a--;
        if ( flag) b--;

        if (!x)
        {
            while (a)
            {
                cout<<0; a--;
            }
            while (b)
            {
                cout<<1; b--;
            }
            a = b = 0;
        }

        if (x)
        {
            flag = !flag;
        }
    }

    return 0;
}


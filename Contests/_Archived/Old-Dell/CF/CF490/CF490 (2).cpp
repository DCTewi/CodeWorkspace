#include <cstdio>
#include <iostream>

using namespace std;
const int MAX = 105;
char dat[MAX];
int n, step[MAX];

void backup(int);

int main()
{
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>dat[i];
    }

    int nn = n, fir = 0;
    for (int i = 0; nn > 1; i++)
    {
        if (n % nn == 0) step[i] = nn;
        nn--;
        fir = i;
    }

    for (int i = fir; i >= 0; i--)
    {
        backup(step[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout<<dat[i];
    }

    return 0;
}

void backup(int step)
{
    char temp[step];
    for (int i = 0; i < step; i++)
    {
        temp[i] = dat[i];
    }

    for (int i = step - 1; i >= 0; i--)
    {
        dat[i] = temp[step - 1 - i];
    }

    return;
}

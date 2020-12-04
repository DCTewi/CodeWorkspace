// WA 4
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 5;
int n, x;
int a[MAXN], mina[MAXN];
int l = 0, r = 0;

inline int Max(int a, int b)
{
    return a > b? a: b;
}

int max_sub(int data[])
{
    int max, imax;
    int i, istart;

    max = imax = data[0];
    l = r = istart = 0;
    for (i = 1; i < n; i++)
    {
        if (imax >= 0)
        {
            imax += data[i];
        }
        else
        {
            imax = data[i];
            istart = i;
        }
        if (imax > max)
        {
            max = imax;
            r = istart;
            l = i;
        }
    }

    return Max(max, 0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mina[i] = -a[i];
    }

    if (x == 0)
    {
        cout<<max_sub(a)<<"\n";
    }
    else if (x > 0)
    {
        cout<<max_sub(a) * x<<"\n";
    }
    else if (x < 0)
    {
        max_sub(mina);
        if (l != r)
        {
            for (int i = r; i <= l; i++)
            {
                a[i] *= x;
            }
        }
        else if (a[l] < 0)
        {
            a[l] *= x;
        }

        cout<<max_sub(a)<<"\n";
    }

    return 0;
}
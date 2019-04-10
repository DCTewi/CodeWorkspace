#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MAXN = 2e4 + 5;
const int M[5] = {12323, 15121, 16633, 18233, 19991};
ll f[5][MAXN], a[MAXN], b[5];

int readB()
{
    string str;cin>>str;

    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < str.size(); i++)
        {
            b[k] *= 10;
            b[k] += (int)(str[i] - '0');
            b[k] %= M[k];
        }
    }
}

int main()
{
    int t;scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        memset(b, 0, sizeof(b));
        readB();
        bool flag = true;

        for (int k = 0; k < 5; k++)
        {
            f[k][0] = a[0] % M[k];
            for (int i = 1; i < n; i++)
            {
                f[k][i] = (f[k][i - 1] * a[i]) % M[k];
            }
            if (f[k][n - 1] != b[k]) flag = false;
            if (!flag) break;
        }

        if (flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}

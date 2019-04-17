#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e2 + 5;

int p, k, s;
string str = " ", word[10];
int ans = 0;
int f[MAXN][MAXN], sum[MAXN][MAXN];

inline bool checkif(int l, int r)
{
    string sub = str.substr(l, r - l + 1);
    for (int i = 0; i < s; i++)
    {
        if (sub.find(word[i]) == 0) return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>p>>k;
    for (int i = 0; i < p; i++)
    {
        string in; cin>>in;
        str += in;
    }
    cin>>s;
    for (int i = 0; i < s; i++)
    {
        cin>>word[i];
    }

    for (int j = str.size() - 1; j > 0;j--)
    {
        for (int i = j; i > 0; i--)
        {
            sum[i][j] = sum[i + 1][j];
            if (checkif(i, j)) sum[i][j]++;
        }
    }

    for (int p = 1; p <= k; p++)
    {
        for (int i = 1; i < str.size(); i++)
        {
            for (int j = p - 1; j < i; j++)
            {
                f[i][p] = max(f[i][p], f[j][p - 1] + sum[j + 1][i]);
            }
        }
    }

    cout<<f[str.size() - 1][k]<<"\n";

    return 0;
}

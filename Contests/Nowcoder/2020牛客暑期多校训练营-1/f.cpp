#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int pre[100005];
string a, b;
int ta, tb;

void get_prefix(const char *str, const char *strend)
{
    int n = strend - str;
    pre[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        int j = pre[i - 1];
        for (; j > 0 && str[i] != str[j]; j = pre[j - 1])
            ;
        if (str[i] == str[j])
            ++j;
        pre[i] = j;
    }
}

int cmp()
{
    for (int i = 0; i < 1000006; ++i)
    {
        int ap = i % a.length(), bp = i % b.length();
        if (a[ap] != b[bp])
            return a[ap] - b[bp];
        if (i && ap == 0 && bp == 0)
            return 0;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    while (cin >> a >> b)
    {
        get_prefix(a.c_str(), a.c_str() + a.length());
        ta = a.length() - pre[a.length() - 1];

        get_prefix(b.c_str(), b.c_str() + b.length());
        tb = b.length() - pre[b.length() - 1];

        int ans;
        if (ta == tb && a.length() % ta == 0 && b.length() % tb == 0)
        {
            if (strncmp(a.c_str(), b.c_str(), ta) == 0)
            {
                cout << "=\n";
                continue;
            }
        }

        ans = cmp();
        if (ans < 0)
            cout << "<\n";
        else if (ans == 0)
            cout << "=\n";
        else
            cout << ">\n";
    }

    return 0;
}
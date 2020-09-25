#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 5;
int n, m;

template <class T> T read()
{
    T x = 0; int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

inline int getid(char ch)
{
    return isupper(ch) ? ch - 'A' + 26 : ch - 'a';
}

void decrypto(string x, string &y)
{
    string salt(x);
    while (salt.size() < y.size())
    {
        salt = salt + x;
    }
    for (int i = 0; i < static_cast<int>(y.size()); i++)
    {
        int b = getid(salt[i]), now = getid(y[i]);
        if (now < b) now += 52;
        int a = (now - b);
        y[i] = (a > 25) ? a - 26 + 'A' : a + 'a';
    }
}

int main()
{
    n = read<int>(), m = read<int>();
    vector<pair<int, int>> p(m);
    for (int i = m - 1; i >= 0; i--)
    {
        int x = read<int>(), y = read<int>();
        p[i] = make_pair(x, y);
    }

    vector<string> pool(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> pool[i];
    }

    for (auto xy : p)
    {
        decrypto(pool[xy.first], pool[xy.second]);
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%s", pool[i].c_str());
        if (i != n) puts("");
    }

    return 0;
}

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

void crypto(string x, string &y)
{
    string salt(x);
    while (salt.size() < y.size())
    {
        salt = salt + x;
    }
    cout << salt << "\n";
    for (int i = 0; i < static_cast<int>(y.size()); i++)
    {
        int b = getid(salt[i]), now = getid(y[i]);
        int a = (now + b) % 52;
        y[i] = (a > 25) ? a - 26 + 'A' : a + 'a';
    }
}

int main()
{
    n = read<int>(), m = read<int>();
    vector<pair<int, int>> p(m);
    for (int i = 0; i < m; i++)
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
        cout << pool[xy.first] << "->" << pool[xy.second] << "\n";
        crypto(pool[xy.first], pool[xy.second]);
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%s", pool[i].c_str());
        if (i != n) puts("");
    }

    return 0;
}
/*
3 3
1 2
2 3
3 1
PKUSAA
beijing
ccpc

3 3
1 2
2 3
3 1
HAlVsq
QOcbINV
SQrd

2 1
1 2
Q
K
 */
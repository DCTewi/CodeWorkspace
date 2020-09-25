#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> T read()
{
    T x = 0; int ch = getchar(), w = 0;
    while (!isdigit(ch)) w |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return w ? -x : x;
}

int main()
{
    list<string> l;
    int n = read<int>();
    for (int i = 0; i < n; i++)
    {
        string opt; cin >> opt;
        if (opt == "in")
        {
            string str; cin >> str;
            l.push_back(str);
        }
        else if (opt == "out")
        {
            l.pop_front();
        }
        else if (opt == "q")
        {
            cout << (l.size() ? (*l.begin()) : "NULL");
            puts("");
        }
    }

    return 0;
}

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

map<char, char> mat ({{']', '['}, {'}', '{'}, {')', '('}});

bool check(const string &s)
{
    stack<char> stk;

    for (char ch : s)
    {
        if (ch == ')' || ch == ']' || ch == '}')
        {
            if (!stk.size()) return false;

            if (stk.top() != mat[ch]) return false;

            stk.pop();
        }
        else
        {
            stk.push(ch);
        }
    }
    return !stk.size();
}

int main()
{
    int _T; scanf("%d", &_T);
    while (_T--)
    {
        string s; cin >> s;
        puts(check(s) ? "Yes" : "No");
    }
    return 0;
}
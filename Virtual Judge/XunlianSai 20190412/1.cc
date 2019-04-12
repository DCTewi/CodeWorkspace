//F
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;

map<char, bool> optdic;
string str, s;

inline bool isopt(char ch)
{
    return optdic.count(ch);
}

bool iserror()
{
    for (int i = 1; i < s.size(); i++)
    {
        if (isalpha(s[i]) && isalpha(s[i - 1]))
        {
            return true;
        }
        if (isopt(s[i]) && isopt(s[i - 1]))
        {
            return true;
        }
        if (s[i] == ')' && s[i - 1] == '(')
        {
            return true;
        }

        if (isopt(s[i]) && s[i - 1] == '(')
        {
            return true;
        }
        if (s[i] == ')' && isopt(s[i - 1]))
        {
            return true;
        }
    }

    int lef = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            lef++;
        }
        if (s[i] == ')')
        {
            lef--;
            if (lef < 0 || (lef == 0 && i != s.size() - 1)) return true;
        }
    }
    if (lef) return true;

    return false;
}

bool issubproper(int p)
{
    int con = 0, i = p + 1;
    for (; s[i] != ')'; i++)
    {
        if (isopt(s[i])) con++;
        if (s[i] == '(')
        {
            if (!issubproper(i)) return false;
        }
        s[i] = ' ';
    }

    s[i] = ' ';
    //cout<<endl<<s<<" "<<con<<endl;

    if (con != 1) return false;

    return true;
}

void initopt()
{
    optdic['+'] = optdic['-'] = optdic['*'] = optdic['/'] = optdic['%'] = true;
    //optdic['('] = optdic[')'] = true;
}

int main()
{
    initopt();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    getline(cin, str);
    s = "(";
    
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
        {
            s += str[i];
        }
    }

    s += ")";

    if (iserror()) return 0 * puts("error");

    if (issubproper(0)) return 0 * puts("proper");

    return 0 * puts("improper");
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t; cin >> s;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (isdigit(s[i]) && s[i + 1] == '(')
        {
            t += s[i];
            t += '*';
        }
        else if (s[i] == ')' && isdigit(s[i + 1]))
        {
            t += ")*";
        }
        else if (s[i] == ')' && s[i + 1] == '(')
        {
            t += ")*";
        }
        else
        {
            t += s[i];
        }
    }
    t += s[s.size() - 1];
    cout << t << "\n";
    return 0;
}
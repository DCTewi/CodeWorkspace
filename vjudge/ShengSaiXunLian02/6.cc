//F
#include <bits/stdc++.h>
using namespace std;
string s;

inline bool dif(char a, char b, char c)
{
    return a != b && b != c && a != c;
}

int main()
{
    cin>>s;
    int len = s.size();
    char l = s[0], r = s[s.size() - 1];
    
    if (len <= 3) return 0 * puts("1");

    if (dif(s[0], s[1], s[2])) return 0 * puts("1");
    
    if (dif(s[len - 1], s[len - 2], s[len - 3])) return 0 * puts("1");
    
    if (dif(s[0], s[1], s[len - 1])) return 0 * puts("2");
    
    if (dif(s[0], s[len - 1], s[len - 2])) return 0 * puts("2");

    for (int i = 1; i < len - 1; i++)
    {
        if (dif(s[i - 1], s[i], s[i + 1])) return 0 * puts("2");
    }
    
    if (s[0] != s[1] || s[len - 1] != s[len - 2])
    {
        return 0 * puts("3");
    }
    
    if (l == r) puts("4");
    else puts("3");
    
    return 0;
}


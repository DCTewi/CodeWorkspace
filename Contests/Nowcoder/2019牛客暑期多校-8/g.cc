#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

string s;
char st[MAXN];
int top = -1, ans = 0;

inline void push(char &c)
{
    st[++top] = c;
}

inline void pop()
{
    top--;
}

inline void show()
{
    for (int i = 0; i <= top; i++)
    {
        cout << st[i] << " ";
    }
    cout << "\n";
}

int main()
{
    cin >> s;
    
    push(s[0]);
    for (int i = 1; i <= (int)s.size(); i++)
    {
        if (i != (int)s.size()) push(s[i]);

        if (top >= 2 && st[top] == st[top - 1] && st[top] == st[top - 2])
        {
            pop(); pop(); pop(); ans++;
        }
#ifdef DEBUG
        show();
#endif
    }

    cout << ans << "\n";

    return 0;
}

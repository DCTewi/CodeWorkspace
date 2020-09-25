#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
    {
        string s; cin >> s;

        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] == 'y') continue;
            if (s[i] == 'z') {s[i] = 'b'; break;}
            else break;
        }

        cout << s << "\n";
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string t;
int q;

int main()
{
    ios::sync_with_stdio(0);

    cin >> t >> q;
    while (q--)
    {
        string s; cin >> s;

        if (s == t) cout << "jntm!\n";
        else
        {
            int ls = s.size(), lt = t.size();
            if (ls == lt) cout << "friend!\n";
            else if (ls > lt)
            {
                if (s.find(t) != string::npos)
                {
                    cout << "my teacher!\n";
                }
                else cout << "senior!\n";
            }
            else
            {
                if (t.find(s) != string::npos)
                {
                    cout << "my child!\n";
                }
                else cout << "oh, child!\n";
            }
        }
    }

    return 0;
}

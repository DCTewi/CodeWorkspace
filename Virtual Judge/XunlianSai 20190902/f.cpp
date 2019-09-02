#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);

    string s; cin >> s;
    list<char> ans;
    auto it = ans.begin();

    for (char ch : s)
    {
        if (ch == 'L')
        {
            if (it != ans.begin()) it--;
            continue;
        }
        if (ch == 'R')
        {
            if (it != ans.end()) it++;
            continue;
        }

        ans.insert(it, ch);
    }

    for (char ch : ans)
    {
        cout << ch;
    }
    cout << "\n";

    return 0;
}

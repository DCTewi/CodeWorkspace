#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

string str;
int len;
map<char, pair<int, int>> dir;

bool check(string s)
{
    map<char, int> times;
    int siz = s.size();
    for (int i = 0; i < siz; i++)
    {
        times[s[i]]++;
    }
    int cnt = 0;
    for (auto &p : times)
    {
        // cout << p.first << "," << p.second << endl;
        if (dir[p.first].first > p.second || dir[p.first].second < p.second)
        {
            return false;
        }
        cnt++;
    }
    if (cnt != (int)dir.size()) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("in.txt", "r", stdin);

    while (cin >> str >> len)
    {
        dir.clear();
        for (char i = 'a'; i <= 'z'; i++)
        {
            int l, r; cin >> l >> r;
            if (l || r) dir[i] = make_pair(l, r);
        }

        int mint = 0;
        for (auto &p : dir)
        {
            mint += p.second.first;
        }
        if (mint > len)
        {
            cout << "-1\n"; continue;
        }

        string ans (len, 'z'); int flag = 0;
        priority_queue<string> pq;
        int R = str.size() - len + 1;
        for (int i = 0; i < R; i++)
        {
            pq.push(str.substr(i, len));
            // cout << now << endl;
        }
        while (pq.size())
        {
            if (check(pq.top()))
            {
                flag = 1;
                ans = min(ans, pq.top());
                break;
            }
            pq.pop();
        }
        if (flag)
        {
            cout << ans << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}

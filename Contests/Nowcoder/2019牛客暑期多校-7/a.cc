#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_perf(string sec)
{
    int n = sec.size();
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n) {
        if (sec[(i + k) % n] == sec[(j + k) % n]) {
            k++;
        } else {
            sec[(i + k) % n] > sec[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j) i++;
            k = 0;
        }
    }
    i = min(i, j);
    return !i;
}

int main()
{
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
    {
        string s; cin >> s;
        vector<string> ans;
        {
            string tmp; tmp += s[0];
            for (int i = 1; i < (int)s.size(); i++)
            {
                if (s[i] == '0' && s[i - 1] == '1')
                {
                    ans.emplace_back(tmp);
                    tmp.clear();
                }
                tmp += s[i];
            }
            ans.emplace_back(tmp);
        }
        int flag = 0;
        do
        {
            vector<string> now;
            string stage;
            for (int i = 0; i < (int)ans.size(); i++)
            {
                if (!is_perf(stage + ans[i]))
                {
                    now.emplace_back(stage); stage.clear();
                }
                stage += ans[i];
            }
            if (stage.size()) now.emplace_back(stage);
            if (now.size() == ans.size()) flag = 1;
            else swap(now, ans);
        }
        while (!flag);

        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

